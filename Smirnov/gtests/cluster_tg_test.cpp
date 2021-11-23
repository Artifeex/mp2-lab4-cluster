#include "pch.h"
#include "../base/cluster.h"
#include "../base/cluster.cpp"
#include "../base/task_generator.cpp"
#include "../base/statistics_manager.cpp"
using namespace std;

TEST(TaskGenerator, can_create_task_generator)
{
	ASSERT_NO_THROW(TaskGenerator tg);
}

TEST(TaskGenerator, throws_when_frequency_is_too_small)
{
	const float frequency = -1;
	const int maxTaskCpu = 5;
	const int maxTaskTacts = 3;

	ASSERT_ANY_THROW(TaskGenerator tg(frequency));
}

TEST(TaskGenerator, throws_when_frequency_is_too_large)
{
	const float frequency = 1.5;
	const int maxTaskCpu = 5;
	const int maxTaskTacts = 3;

	ASSERT_ANY_THROW(TaskGenerator tg(frequency));
}

TEST(TaskGenerator, throws_when_maxTaskCpu_is_too_small)
{
	const float frequency = 1.5;
	const int maxTaskCpu = -2;
	const int maxTaskTacts = 3;

	ASSERT_ANY_THROW(TaskGenerator tg(frequency, maxTaskCpu));
}

TEST(TaskGenerator, throws_when_maxTaskTacts_is_too_small)
{
	const float frequency = 1.5;
	const int maxTaskCpu = 5;
	const int maxTaskTacts = -3;

	ASSERT_ANY_THROW(TaskGenerator tg(frequency, maxTaskCpu, maxTaskTacts));
}

TEST(TaskGenerator, can_create_task)
{
	const float frequency = 0.7;
	const int maxTaskCpu = 5;
	const int maxTaskTacts = 5;
	TaskGenerator tg(frequency, maxTaskCpu, maxTaskTacts);

	ASSERT_NO_THROW(tg.GenerateTask());
}

TEST(Cluster, can_create_cluster)
{
	float frequency = 0.7f;
	int CPU = 10;
	int tacts = 100;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();

	ASSERT_NO_THROW(Cluster cluster(tacts, CPU,queueSize, taskGenerator, st));
}

TEST(Cluster, throws_when_create_cluster_with_too_small_CPU)
{
	float frequency = 0.7f;
	int CPU = 0;
	int tacts = 100;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();

	ASSERT_ANY_THROW(Cluster cluster(tacts, CPU, queueSize, taskGenerator, st));
}

TEST(Cluster, throws_when_create_cluster_with_too_more_CPU)
{
	float frequency = 0.7f;
	int CPU = 500;
	int tacts = 100;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();

	ASSERT_ANY_THROW(Cluster cluster(tacts, CPU, queueSize, taskGenerator, st));
}

TEST(Cluster, throws_when_create_cluster_with_too_more_tacts)
{
	float frequency = 0.7f;
	int CPU = 10;
	int tacts = 10000;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();

	ASSERT_ANY_THROW(Cluster cluster(tacts, CPU, queueSize, taskGenerator, st));
}

TEST(Cluster, throws_when_create_cluster_with_too_small_tacts)
{
	float frequency = 0.7f;
	int CPU = 10;
	int tacts = 3;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();

	ASSERT_ANY_THROW(Cluster cluster(tacts, CPU, queueSize, taskGenerator, st));
}

TEST(Cluster, can_start_cluster)
{
	float frequency = 0.7f;
	int CPU = 10;
	int tacts = 100;
	int queueSize = 10;
	StatisticsManager* st = new StatisticsManager();
	TaskGenerator* taskGenerator = new TaskGenerator();
	Cluster cluster(tacts, CPU, queueSize, taskGenerator, st);

	ASSERT_NO_THROW(cluster.Start());
}


