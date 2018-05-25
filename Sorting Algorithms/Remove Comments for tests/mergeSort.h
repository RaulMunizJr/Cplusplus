
template <class T>
void merge(T * arr, int start, int mid, int end)
{
	int n1 = (mid - start) + 1;
	int n2 = end - mid;

	T * L = new T[n1];// + 1];
		T * R = new T[n2];// + 1];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[start + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[mid + j + 1];
	}

	int left = 0;
	int right = 0;
	int arrIndex = 0;

	while(left < n1 && right < n2)
	{
		if (L[left] <= R[right])
		{
			arr[arrIndex] = L[left];
			left++;
		}
		else if(L[left] > R[right])
		{
			arr[arrIndex] = R[right];
			right++;
		}

	}
}

template <class T>
void mergeSort(T * arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start +(end -1))/2;

		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

