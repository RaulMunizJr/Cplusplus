

template <class T>
void swap(T * arr, int x, int y)
{
	T buff = arr[x];
	arr[x] = arr[y];
	arr[y] = buff;
}

template <class T>
int partition(T * arr, int start, int end)
{
	//Find pivot
	int pivot = end / 2;
	int smallIndex = start;
	int	index;

	//sort partition
	for (index = start + 1; index <= end; index++)
	{
		if (arr[index] < arr[pivot])
		{
			smallIndex++;
			swap(arr, smallIndex, index);
		}
	}
	swap(arr, pivot, smallIndex);

	return smallIndex;
}

template <class T>
void quicksort(T * arr, int start, int end)
{
	if (start < end)
	{
		int q = partition(arr, start, end);
		quicksort(arr, start, q - 1);
		quicksort(arr, q + 1, end);
	}
}
