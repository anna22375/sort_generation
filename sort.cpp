#include <vector>
#include <cmath>
#include <iostream>
#include "sort.h"

template<typename T>
void sort(std::vector<T> &arr) {
  introsort(arr);
}

template<typename T>
void introsort(std::vector<T> &arr) {
  const int maxdepth = log(arr.size());
  introsort1(arr, 0, arr.size()-1, maxdepth);
}

template<typename T>
void introsort1(std::vector<T> &arr, int x1, int x2, int maxdepth) {

  if ((x2-x1) < 1)
    return;
  else {
    if (maxdepth == 0)
      heapsort(arr, x1, x2);
    else {
      T p = arr[(x2+x1)/2];
      int xl = x1, xr = x2;

      while (xl <= xr)
      {
        while (arr[xl] < p)
          xl++;
        while (arr[xr] > p)
          xr--;
        if (xl <= xr)
          std::swap (arr[xl++], arr[xr--]);
      }

      if (x1 < xr)
        introsort1(arr, x1, xr, maxdepth);
      if (x2 > xl)
        introsort1(arr, xl, x2, maxdepth);
    }
  }
}

template<typename T>
void siftDown(std::vector<T> &arr,int i, int n) {
  int left = 2*i+1;
  int right = 2*i+2;
  int max = i;

  if ((left < n) && (arr[left] > arr[max]))
    max = left;
  if ((right < n) && (arr[right] > arr[max]))
    max = right;
  if (i != max) {
    std::swap(arr[i],arr[max]);
    siftDown(arr,max,n);
  }
}

template<typename T>
void makeHeap(std::vector<T> &arr,int x1,int x2) {
  int n = x2-x1+1;
  for (int i = x1+n/2-1; i >= x1 ; i--)
    siftDown(arr, i, x2);
}

template<typename T>
void heapsort(std::vector<T> &arr,int x1,int x2) {
  makeHeap(arr, x1, x2);
  int n = x2;
  for (int i = x2; i >= x1; i--)
  {
    std::swap(arr[x1], arr[i]);
    n--;
    siftDown(arr,x1,n);
  }
}
