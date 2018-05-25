
template <class T>
void countingSort(T * arrA, T * arrB, int n, int size)
{
	T * arrC = new T[size];

	for (int i = 0; i < size; i++)
	{
		arrC[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		arrC[arrA[i]] = arrA[arrC[i]] + 1;
	}

	for (int i = 0; i < size; i++)
	{
		arrC[i] = arrC[i] + arrC[i - 1];
	}

	for (int i = size - 1; i > 0; i--)
	{
		arrB[arrC[arrA[i]]] = arrA[i];
		arrC[arrA[i]] = arrC[arrA[i]] - 1;
	}
}


template <class T>
void radixsort(T arr[], int start, int end)           
{
	int mul = 1;
	while (end)
	{
		countsort(arr, start, mul);
		mul *= 10;
		end /= 10;
	}
}
