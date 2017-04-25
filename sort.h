#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;

#define value_t int

value_t rand_num();
char char_rand_num();


template <typename T>
void heapify(int i, vector<T> &mass, int real_size)
{
	int left, right, largest;
	while(true)
	{
		left = 2*i+1;
		right = 2*i+2;
		largest = i;
		if(left < real_size && mass[left] > mass[largest])
		{
			largest = left;
		}
		if(right < real_size && mass[right] > mass[largest])
		{
			largest = right;
		}
		if(largest == i)
		{
			break;
		}
		my_swap(mass, i, largest);
		i = largest;
	}
}

template <typename T>
void my_swap(vector<T> &mass, int pos1, int pos2)
{
	T temp = mass[pos1];
	mass[pos1] = mass[pos2];
	mass[pos2] = temp;
}

template <typename T>
void out(vector<T> &mass, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(mass[i] >= 0)
		{
			cout << mass[i] << "  ";
		}
	}
	cout << endl;
}
#endif // SORT_H
