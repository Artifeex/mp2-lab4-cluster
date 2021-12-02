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
	cout << "Появившихся заданий: " << appearedTasks << endl;
	cout << "Отказанных заданий: " << rejectedTasks << endl;
	cout << "Успешно завершенных заданий: " << completedTasks << endl;
	cout << "Выполняющихся на момент завершения: " << clusterTasks << endl;
	cout << "Оставшихся в очереди на момент завершения: " << queueTasks << endl;
	cout << "Средняя доля загруженности кластера: " << averageWorkload << endl;
	cout << "Число тактов простоя: " << idleTacts << endl;
}


