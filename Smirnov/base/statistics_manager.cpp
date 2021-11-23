#include "statistics_manager.h"

StatisticsManager::StatisticsManager()
{
	appearedTasks = 0;
	rejectedTasks = 0;
	completedTasks = 0;
	queueTasks = 0;
	clusterTasks = 0;
	totalCpuWorked = 0;
	idleTacts = 0;
	averageWorkload = 0;
}

void StatisticsManager::PrintStatistics()
{
	cout << "����������� �������: " << appearedTasks << endl;
	cout << "���������� �������: " << rejectedTasks << endl;
	cout << "������� ����������� �������: " << completedTasks << endl;
	cout << "������������� �� ������ ����������: " << clusterTasks << endl;
	cout << "���������� � ������� �� ������ ����������: " << queueTasks << endl;
	cout << "������� ���� ������������� ��������: " << averageWorkload << endl;
	cout << "����� ������ �������: " << idleTacts << endl;
}


