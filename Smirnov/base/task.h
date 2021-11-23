#pragma once
class Task
{
private:
	int needTacts;
	int needCPU;
	int startTact;
public:
	Task(int _needTacts = 0, int _needCPU = 0) : needTacts(_needTacts), needCPU(_needCPU)
	{
		startTact = -1;
	}
	void SetStartTact(int _startTact) { startTact = _startTact; }
	int GetStartTact() { return startTact; }
	int GetNeedTacts() { return needTacts; }
	int GetNeedCPU() { return needCPU; }
};

