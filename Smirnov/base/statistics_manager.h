#pragma once
#include <iostream>
using namespace std;

class StatisticsManager
{
private:
	int appearedTasks; 
	int rejectedTasks; 
	int completedTasks; 
	int queueTasks;
	int clusterTasks; 
	int totalCpuWorked; 
	float averageWorkload;
	int idleTacts;
public:
	StatisticsManager();

	void AppearedTask() { appearedTasks++; }
	void RejectedTask() { rejectedTasks++; }
	void CompletedTask() { completedTasks++; }
	void IdleTact() { idleTacts++; }
	void QueueTasks(int count) { queueTasks = count; }
	void ClusterTasks(int count) { clusterTasks = count; }
	void CpuPerTact(int cpu) { totalCpuWorked += cpu; }
	void AverageWorkload(int totalCpu, int totalTacts) { averageWorkload =  totalCpuWorked / float(totalCpu * totalTacts); }
	void PrintStatistics();
	void ClearStat() { *this = StatisticsManager(); };
};

