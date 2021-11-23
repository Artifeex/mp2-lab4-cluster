#pragma once
#include "statistics_manager.h"
#include "task_generator.h"
#include "queue.h"
using namespace std;

const int MaxClusterCpu = 64;
const int MaxClusterTacts = 1000;
const int MinClusterCpu = 5;
const int MinClusterTacts = 5;

class Cluster
{
private:
	int workTacts;
	int totalCpu;
	int activeCpu;
	TaskGenerator* taskGenerator;
	Queue<Task> queueTasks;
	vector<Task> activeTasks;
	StatisticsManager* statManager;

	void UpdateQueueTasks();
	bool CanExecuteTask();
	void ExecuteTask(int currentTact);
	void CheckTasks(int currentTact);
	int TasksOnCluster();
public:
	Cluster(int _workTacts, int _totalCPU, int _queueSize, TaskGenerator* _taskGenerator, StatisticsManager* _statManager);

	void Start();
};

