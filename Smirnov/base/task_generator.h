#pragma once
#include "task.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class TaskGenerator
{
private:
	float frequency;
	int maxTaskCpu;
	int maxTaskTacts;
public:
	TaskGenerator(float _frequency = 0.5, int _maxTaskCpu  = 32, int _maxTaskTacts = 10);

	void ChangeFrequency(float _frequency);
	void ChangeMaxTaskCpu(int _maxTaskCpu);
	void ChangeMaxTaskTacts(int _maxTaskTacts);
	Task* GenerateTask();
};

