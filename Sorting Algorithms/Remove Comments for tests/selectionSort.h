
template <class T>
void selectionSort(T * arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				T buff = arr[j];
				arr[j] = arr[i];
				arr[i] = buff;
			}
		}
	}
}
