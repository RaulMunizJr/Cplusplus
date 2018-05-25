

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

template <class T>
class minHeap
{
private:

	T * items;
	int numItems;

	int parent(int i)
	{
		return (i - 1) / 2;
	}

	int leftChild(int i)
	{
		return (2 * i) + 1;
	}

	int rightChild(int i)
	{
		return (leftChild(i)) + 1;
	}

public:
	minHeap(int size)
	{	
		items = new T[size];
		numItems = 0;
	}

//check for minHeap property violations
	bool leaves(int i)
	{
		if (leftChild(i) >= numItems)
		{
			return false;
		}
		else if (rightChild(i) == numItems)
		{
			if (items[leftChild(i)] < items[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			T smallest = min(items[leftChild(i)], items[rightChild(i)]);

			if (smallest < items[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	void insert(T x)
	{
		items[numItems] = x;
		numItems++;

		//bubble x up heap
		int current = numItems = 1;
		while (items[current] < items[parent(current)])
		{
			swap(items[current], items[parent(current)]);
			current = parent(current);
		}
	}

	T extractMin()
	{
		T output = items[0];

		//swap last item and root
		items[0] = items[numItems - 1];
		numItems--;

		//bubble item down heap
		int current = 0;
		while (childProblem(current))
		{
			//swap current with children
			if (rightChild(current) == numItems)
			{
				swap(items[current], items[lchild(current)]);
				current = lchild(current);
			}
			else //2 children case
			{
				if (items[lchild(current)] < items[rchild(current)])
				{
					swap(items[current], items[lchild(current)]);
					current = leftChild(current);
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
