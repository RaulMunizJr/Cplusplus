
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class minHeap
{
private:
	T * items;
	int numItems;

	//return index of index i's parent
	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int lchild(int i)
	{
		return 2 * i + 1;
	}

	int rchild(int i)
	{
		return lchild(i) + 1;
	}

public:
	minHeap()
	{
		items = new T[100];
		numItems = 0;
	}

	minHeap(int cap)
	{
		items = new T[cap];
		numItems = 0;
	}

	//is item at index i
	//in violation with
	//either of it's children
	bool childProblem(int i)
	{
		if (lchild(i) >= numItems) //  0 children)
		{
			return false;
		}
		else if (rchild(i) == numItems) // 1 child)
		{
			if (items[lchild(i)] < items[i])
				return true;
			else
				return false;
		}
		else //2 children
		{
			T smallerVal = min(items[lchild(i)], items[rchild(i)]);
			if (smallerVal < items[i])
				return true;
			else
				return false;
		}


	}

	bool empty()
	{
		if (numItems == 0)
			return true;
		else
			return false;
	}

	//add x to the min heap
	//O(log n) worst case run time
	void insert(T x)
	{
		//step 1: put x at bottom of heap
		items[numItems] = x;
		numItems++;

		//step 2: bubble x up heap
		//until there is no more violation
		int current = numItems - 1;
		while (items[current] < items[parent(current)])
		{
			swap(items[current], items[parent(current)]);
			current = parent(current);
		}
	}

	//O(log n) worst case run time
	T extractMin()
	{
		//write down root item for output
		T output = items[0];

		//put bottom heap item at root
		//decrement numItems
		items[0] = items[numItems - 1];
		numItems--;

		//bubble current item down heap
		//until there is no more violation
		int current = 0;
		while (childProblem(current))
		{
			//swap current with smaller child
			if (rchild(current) == numItems) // 1 child)
			{
				swap(items[current], items[lchild(current)]);
				current = lchild(current);
			}
			else //2 children case
			{
				if (items[lchild(current)] < items[rchild(current)])
				{
					swap(items[current], items[lchild(current)]);
					current = lchild(current);
				}
				else
				{
					swap(items[current], items[rchild(current)]);
					current = rchild(current);
				}
			}
		}
		return output;
	}
};

template <class T>
void heapSort(T * items, int start, int end)
{
	minHeap<T> H(end - start + 1);
	for (int i = start; i <= end; i++)
	{
		H.insert(items[i]);
	}

	for (int i = start; i <= end; i++)
	{
		items[i] = H.extractMin();
	}
}
