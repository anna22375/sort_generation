#include "stdafx.h"
#include <iostream>
#include <cstdlib>

extern const int NMAX = 10000;
extern int arr[NMAX + 1];

using namespace std;


void heapify(int *arr, int pos, int n) {//pos - позиция корня в куче, n - количество элементов в массиве
	while (2 * pos + 1 < n) {
		//пока не вышли за границу массива
		int t = 2 * pos + 1; //находим первого сына
		if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
			//если второй сын существет и больше чем первый
		{
			t = 2 * pos + 2;//берем его
		}
		if (arr[pos] < arr[t])
		{
			//если наибольший из сыновей больше
			//чем предок, то меняем их местами
			swap(arr[pos], arr[t]);
			pos = t;//теперь предком является следующий элемент
		}
		else break;
		//иначе куча с головой в pos построена
	}
}

void heap_make(int *arr, int n)//функция построения кучи
{
	for (int i = n - 1; i >= 0; i--)
	{
		heapify(arr, i, n);// функция добавления нового элемента в кучу
	}
}

void heap_sort(int *arr, int n)//собственно, сама сортировка
{
	heap_make(arr, n);//делаем кучу(пирамиду)
	while (n > 0)
	{
		swap(arr[0], arr[n - 1]);
		n--;
		heapify(arr, 0, n);
	}
}