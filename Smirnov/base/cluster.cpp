#include "cluster.h"

void Cluster::UpdateQueueTasks()
{
	Task* generatedTask;
	generatedTask = taskGenerator->GenerateTask();
	if (generatedTask != NULL)
	{
		statManager->AppearedTask();
		if (!queueTasks.IsFull() && generatedTask->GetNeedCPU() <= totalCpu)
		{
			queueTasks.Push(*generatedTask);
		}
		else
		{
			statManager->RejectedTask(); 
		}
	}
	delete generatedTask;
}

bool Cluster::CanExecuteTask()
{
	if (!queueTasks.IsEmpty() && totalCpu - activeCpu >= queueTasks.GetElem().GetNeedCPU())
		return true;
	else
		return false;
}

void Cluster::ExecuteTask(int currentTact)
{
	for (size_t i = 0; i < activeTasks.size(); i++)
	{
		if (activeTasks[i].GetStartTact() == -1)
		{
			activeTasks[i] = queueTasks.Get();
			activeTasks[i].SetStartTact(currentTact);
			activeCpu += activeTasks[i].GetNeedCPU();
			return;
		}
	}
	activeTasks.push_back(queueTasks.Get());
	activeTasks[activeTasks.size() - 1].SetStartTact(currentTact);
	activeCpu += activeTasks[activeTasks.size() - 1].GetNeedCPU();
}

void Cluster::CheckTasks(int currentTact) 
{
	for (size_t i = 0; i < activeTasks.size(); i++)
	{
		if (currentTact - activeTasks[i].GetStartTact() == activeTasks[i].GetNeedTacts())
		{
			activeTasks[i].SetStartTact(-1);
			activeCpu -= activeTasks[i].GetNeedCPU();
			statManager->CompletedTask();
		}
	}
}

int Cluster::TasksOnCluster()
{
	int result = 0;
	for (size_t i = 0; i < activeTasks.size(); i++)
	{
		if (activeTasks[i].GetStartTact() != -1)
			result++;
	}
	return result;
}

Cluster::Cluster(int _workTacts, int _totalCPU, int _queueSize, TaskGenerator* _taskGenerator, StatisticsManager* _statManager)
{
	if (_totalCPU < MinClusterCpu || _totalCPU > MaxClusterCpu)
		throw string("Неправильное число процессоров кластера\n");
	else if (_workTacts < MinClusterTacts || _workTacts > MaxClusterTacts)
		throw string("Неправильное число тактов кластера\n");
	else if (_queueSize < MinQueueSize || _queueSize > MaxQueueSize)
		throw  string("Неправильный размер очереди задач\n");
	queueTasks = Queue<Task>(_queueSize);
	workTacts = _workTacts;
	totalCpu = _totalCPU;
	activeCpu = 0;
	taskGenerator = _taskGenerator;
	statManager = _statManager;
}

void Cluster::Start()
{
	int currentTact = 0;
	while (workTacts - currentTact != 0)
	{
		CheckTasks(currentTact); 
		UpdateQueueTasks();
		while (CanExecuteTask()) 
		{
			ExecuteTask(currentTact);
		}
		if (activeCpu == 0)
			statManager->IdleTact(); 
		statManager->CpuPerTact(activeCpu);
		currentTact++;
	}
	statManager->ClusterTasks(TasksOnCluster());
	statManager->QueueTasks(queueTasks.GetCountElements());
	statManager->AverageWorkload(totalCpu, workTacts);
}
