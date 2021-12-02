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
		cout << "������� �������� q(������� ��������� �������) �� 0 �� 1" << endl;
		cin >> frequency;
		cout << "������� ����� �����������(������� " << MinClusterCpu << " �������� " << MaxClusterCpu << ")" << endl;
		cin >> cpu;
		cout << "������� ����� ������(������� " << MinClusterTacts << " �������� " << MaxClusterTacts << ")" << endl;
		cin >> tacts;
		cout << "������� ������ ������� �����(������� " << MinQueueSize << " �������� " << MaxQueueSize << ")" << endl;
		cin >> queueSize;
		cout << "������� ������������ ����� ��������������� ����������� ��� ���������� ����� ������" << endl;
		cin >> maxTaskCpu;
		cout << "������� ������������ ����� ������ ��� ���������� ����� ������" << endl;
		cin >> maxTaskTacts;
		cout << "���������� ������: " << endl;
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