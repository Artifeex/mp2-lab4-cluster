#include "pch.h"
#include "../base/queue.h"

TEST(Queue, can_create_queue_with_positive_length)
{ 
	const int size = 6;
	ASSERT_NO_THROW(Queue<int> q(size));
}

TEST(Queue, cant_create_too_small_queue)
{
	const int size = 2;
	ASSERT_ANY_THROW(Queue<int> q(size));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
	const int size = -2;
	ASSERT_ANY_THROW(Queue<int> q(size));
}

TEST(Queue, cant_create_too_large_queue)
{
	const int size = MaxQueueSize + 1;
	ASSERT_ANY_THROW(Queue<int> q(size));
}

TEST(Queue, can_get_size)
{
	const int size = 6;
	Queue<int> q(size);

	ASSERT_EQ(size, q.GetSize());
}

TEST(Queue, can_push_elem)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);

	ASSERT_NO_THROW(q.Push(value));
}

TEST(Queue, can_check_fullness)
{
	const int size = 6;
	const bool isFull = false;
	int value = 7;
	Queue<int> q(size);

	ASSERT_EQ(isFull, q.IsFull());
}

TEST(Queue, can_get_count_elements)
{
	const int size = 6;
	const int countElements = 1;
	int value = 7;
	Queue<int> q(size);
	q.Push(value);

	ASSERT_EQ(countElements, q.GetCountElements());
}

TEST(Queue, throws_when_push_with_fullness_queue)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	for (size_t i = 0; i < size; i++)
	{
		q.Push(value);
	}

	ASSERT_ANY_THROW(q.Push(value));
}

TEST(Queue, can_get)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	q.Push(value);
	
	ASSERT_NO_THROW(q.Get());
}

TEST(Queue, can_check_emptiness)
{
	const int size = 6;
	const bool isEmpty = true;
	Queue<int> q(size);

	ASSERT_EQ(isEmpty, q.IsEmpty());
}

TEST(Queue, throws_when_get_with_emptiness_queue)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);

	ASSERT_ANY_THROW(q.Get());
}

TEST(Queue, getted_element_is_equal_to_push_element)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	q.Push(value);

	ASSERT_EQ(value, q.Get());
}

TEST(Queue, get_change_count_elements)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	for (size_t i = 0; i < size; i++)
	{
		q.Push(value);
	}
	q.Get();

	ASSERT_EQ(size - 1, q.GetCountElements());
}

TEST(Queue, can_get_elem)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	q.Push(value);

	ASSERT_NO_THROW(q.GetElem());
}

TEST(Queue, get_elem_does_not_change_count_elements)
{
	const int size = 6;
	int value = 7;
	Queue<int> q(size);
	for (size_t i = 0; i < size; i++)
	{
		q.Push(value);
	}
	q.GetElem();

	ASSERT_EQ(size, q.GetCountElements());
}







