#include "cluster.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	float frequency;
	bool exit = false;
	int cpu = 0;
	int tacts = 0;
	int queueSize = 0;
	int maxTaskCpu = 0;
	int maxTaskTacts = 0;
	StatisticsManager* st = new StatisticsManager();
	while (!exit)
	{
		cout << "¬ведите параметр q(частота по€влени€ заданий) от 0 до 1" << endl;
		cin >> frequency;
		cout << "¬ведите число процессоров(минимум " << MinClusterCpu << " максимум " << MaxClusterCpu << ")" << endl;
		cin >> cpu;
		cout << "¬ведите число тактов(минимум " << MinClusterTacts << " максимум " << MaxClusterTacts << ")" << endl;
		cin >> tacts;
		cout << "¬ведите размер очереди задач(минимум " << MinQueueSize << " максимум " << MaxQueueSize << ")" << endl;
		cin >> queueSize;
		cout << "¬ведите максимальное число задействованных процессоров дл€ выполнени€ одной задачи" << endl;
		cin >> maxTaskCpu;
		cout << "¬ведите максимальное число тактов дл€ выполнени€ одной задачи" << endl;
		cin >> maxTaskTacts;
		cout << "–езультаты работы: " << endl;
		try
		{
			TaskGenerator* taskGenerator = new TaskGenerator(frequency, maxTaskCpu, maxTaskTacts);
			Cluster cluster(tacts, cpu, queueSize, taskGenerator, st);
			cluster.Start();
			st->PrintStatistics();
			delete st;
			exit = true;
		}
		catch (string textError)
		{
			cout << textError;
			exit = false;
		}
	}
	
	
}