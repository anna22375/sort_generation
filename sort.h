#include <vector>
#include <cmath>
#include <iostream>
#include "generation.h"

template<typename T>
void heapSort(std::vector<T> &arr, int a, int b);

template<typename T>
int partition(std::vector<T> &arr, int l, int r);

template <typename T>
void swap(std::vector<T> &arr, int a, int b);

template <typename T>
void heapify(std::vector<T> &vector, int a, int b, int i);

int maxDepth;

template<typename T>
void quickSort(std::vector<T> &arr, int l, int r, int depth) {
    depth++;
    if (depth == maxDepth) {
        heapSort(arr, l, r);
    } else {
        if (l < r) {
            int m = partition(arr, l, r);
            quickSort(arr, l, m - 1, depth);
            quickSort(arr, m + 1, r, depth);
        }
    }
}

template<typename T>
void sort(std::vector<T> &arr) {
    maxDepth = (int) log2(arr.size());
    quickSort(arr, 0, (int) (arr.size() - 1), 0);
}

template<typename T>
int partition(std::vector<T> &arr, int l, int r) {
    int a = l - 1;
    int b = l;
    while (b <= r) {
        if (arr[b] > arr[r]) {
            b++;
        } else {
            a++;
            swap(arr, a, b);
            b++;
        }
    }

    return a;
}

template<typename T>
void heapSort(std::vector<T> &arr, int a, int b) {

    const int n = b - a;

    if (n > 0) {

        for (int i = n / 2 + a; i >= a; i--) {
            heapify(arr, a, b, i);
        }


        for (int i = b; i > a; i--) {
            swap(arr, i, a);
            heapify(arr, a, i - 1, a);
        }
    }
}

template<typename T>
void heapify(std::vector<T> &arr, int a, int b, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*(i - a) + 1 + a;  // left = 2*i + 1
    int r = 2*(i - a) + 2 + a;  // right = 2*i + 2

    // If left child is larger than root
    if (l <= b && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r <= b && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr, i, largest);

        // Recursively heapify the affected sub-tree
        heapify(arr, a, b, largest);
    }
}


template <typename T>
void swap(std::vector<T> &arr, int a, int b) {
    int q = arr[a];
    arr[a] = arr[b];
    arr[b] = q;
}