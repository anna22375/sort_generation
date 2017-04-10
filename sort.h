#include <vector>
#include <algorithm>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int r, int& swapping)
{
	int pivot = arr[r];
	int i = (l - 1);  // Index of smaller element

	for (int j = l; j <= r - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			swapping++;
		}
	}
	swap(&arr[i + 1], &arr[r]);
	swapping++;
	return (i + 1);//return the meaning of pivot
}

void quickSort(int arr[], int l, int r, int& swapping)
{

	if (l < r)
	{
		int pi = partition(arr, l, r, swapping);//pi is partitioning index

		quickSort(arr, l, pi - 1, swapping);
		quickSort(arr, pi + 1, r, swapping);
	}

}

template<typename T>
void sort(std::vector<T> &arr) {
	int swapping;
	quickSort(arr.data(), 0, arr.size() - 1, swapping);
}
