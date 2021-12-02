#pragma once
#include <vector>
using namespace std;

const int MaxQueueSize = 50;
const int MinQueueSize = 5;

template <class T>
class Queue
{
private:
	vector<T> p;
	int size;
	int startIndex;
	int endIndex;
	int countElem;
	int GetNextIndex(int index);
public:
	Queue(int sizeQueue = MaxQueueSize);
	
	bool IsFull();
	bool IsEmpty();
	int GetSize();
	int GetCountElements();
	void Push(const T& value);
	T Get(); // с удалением
	T GetElem();
};

template<class T>
inline bool Queue<T>::IsFull()
{
	if (countElem == size)
		return true;
	else
		return false;
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	if (countElem == 0)
		return true;
	else
		return false;
}

template<class T>
inline int Queue<T>::GetNextIndex(int index)
{
	return ++index % size;
}

template<class T>
inline Queue<T>::Queue(int sizeQueue)
{
	size = sizeQueue;
	if (size < MinQueueSize)
		throw string("TooLittle");
	if (size > MaxQueueSize)
		throw string("TooBig");
	startIndex = 0;
	endIndex = -1;
	countElem = 0;
	p.resize(size);
}

template<class T>
inline int Queue<T>::GetSize()
{
	return size;
}

template<class T>
inline void Queue<T>::Push(const T& value)
{
	if (IsFull())
		throw string("Full");
	else
	{
		endIndex = GetNextIndex(endIndex);
		p[endIndex] = value;
		countElem++;
	}
}

template<class T>
inline T Queue<T>::Get()
{
	if (IsEmpty())
		throw string("Empty");
	else
	{
		T temp = p[startIndex];
		startIndex = GetNextIndex(startIndex);
		countElem--;
		return temp;
	}
}

template<class T>
inline T Queue<T>::GetElem()
{
	if (IsEmpty())
		throw string("Empty");
	else
	{
		return p[startIndex];
	}
}

template<class T>
inline int Queue<T>::GetCountElements()
{
	return countElem;
}


