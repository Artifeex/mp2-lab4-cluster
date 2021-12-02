#include "task_generator.h"

TaskGenerator::TaskGenerator(float _frequency, int _maxTaskCpu, int _maxTaskTacts)
{
    if (_frequency <= 0 || _frequency > 1.0f)
        throw string("������������ �������� �������\n");
    else if (_maxTaskCpu <= 0)
    {
        throw  string("������������ �������� ����� ����������� ��� ����� ������\n");
    }
    else if (_maxTaskTacts <= 0)
    {
        throw string("������������ �������� ���������� ������ ��� ����� ������\n");
    }
    else
    {
        frequency = _frequency;
        maxTaskCpu = _maxTaskCpu;
        maxTaskTacts = _maxTaskTacts;
    }
    srand(time(NULL));
}

void TaskGenerator::ChangeFrequency(float _frequency)
{
    if (_frequency <= 0 || frequency > 1.0f)
        throw string("������������ �������� �������\n");
    frequency = _frequency;
}

void TaskGenerator::ChangeMaxTaskCpu(int _maxTaskCpu)
{
    if(_maxTaskCpu <= 0)
        throw string("������������ �������� ����� ����������� ��� ����� ������\n");
    maxTaskCpu = _maxTaskCpu;
}

void TaskGenerator::ChangeMaxTaskTacts(int _maxTaskTacts)
{
    if (_maxTaskTacts <= 0)
        throw string("������������ �������� ���������� ������ ��� ����� ������\n");
    maxTaskTacts = _maxTaskTacts;
}

Task* TaskGenerator::GenerateTask()
{
    float randValue = (rand() / static_cast<float>(RAND_MAX));
    if (randValue <= frequency)
    {
        int taskCpu = 1 + rand() % maxTaskCpu;
        int taskTacts = 1 + rand() % maxTaskTacts;
        return new Task(taskTacts, taskCpu);
    }
    else
    {
        return NULL;
    }
}

