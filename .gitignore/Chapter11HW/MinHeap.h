#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MinHeap
{
private:
	vector<T> A;

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int left(int i)
	{
		return (i * 2) + 1;
	}

	int right(int i)
	{
		return (i * 2) + 2;
	}

	void heapifyDown(int i)
	{
		// get left and right child of the node at index i
		int l = left(i);
		int r = right(i);

		int smallest = i;

		// compare A[i] with its left amd right child and find the smallest value
		if (l < A.size() && A[l] < A[i])
			smallest = l;

		if (r < A.size() && A[r] < A[smallest])
			smallest = r;

		if (smallest != i)
		{
			swap(A[i], A[smallest]);
			heapifyDown(smallest);
		}
	}

	void heapifyUp(int i)
	{
		if (i < 0 || i > A.size())
			return;

		if (i && A[parent(i)] > A[i])
		{
			swap(A[i], A[parent(i)]);
			heapifyUp(i);
		}
	}

public:
	bool find(T key)
	{
		for (int i = 0; i < A.size(); i++)
			if (A[i] == key)
				return true;
		return false;
	}

	int getSize()
	{
		return A.size();
	}

	bool isEmpty()
	{
		return A.size() == 0;
	}

	void push(T key)
	{
		// insert the new element to the end of vector
		A.push_back(key);

		//call heapifyUp function to change into a heap
		heapifyUp(getSize() - 1);
	}

	T top()
	{
		if (isEmpty())
			return -1;
		return A[0];
	}

	void pop()
	{
		if (isEmpty())
			return;

		A[0] = A.back();
		A.pop_back();

		heapifyDown(0);
	}

	friend ostream& operator <<<>(ostream& out, const MinHeap<T>& obj);
};

template<class T>
ostream& operator <<(ostream& out, const MinHeap<T>& obj)
{
	for (int i = 0; i < obj.A.size(); i++)
		out << obj.A[i] << " ";
	return out;
}
