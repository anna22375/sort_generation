/* я сделала introsort, потому что qsort не такой интересный*/

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>
void sift(vector<T> &a, int k, int m);
template<typename T>
void hsort(vector<T> &a, int n, int l, int r);
template<typename T>
int average(vector<T> &a, int l, int r);
template<typename T>
void qsort(vector<T> &a, int l, int r, int depth);
template<typename T>
T med(T a, T b, T c);


template<typename T>
void sort(vector<T> &arr)
{
    int n = arr.size();
    int depth = int (log(n));
    qsort(arr, 0, n-1, depth);
}

template<typename T>
void sift(vector<T> &a, int k, int m)
{
    T new_el = a[k];
    int child;

    while (k < (m+1)/2)
    {
        child = 2*k+1;
        if (child < m && a[child] < a[child+1])
            child++;
        if (new_el >= a[child])
            break;
        a[k] = a[child];
        k = child;
    }

    a[k] = new_el;
}

template<typename T>
void hsort(vector<T> &a, int n, int l, int r)
{
    for (int i = l + n/2; i>=l; i--)
        sift(a, i, n-1);

    for(int i = r; i > l; i--)
    {
        swap(a[i], a[l]);
        sift(a, l, i-1);
    }
}

template<typename T>
T med(T a, T b, T c)
{
    if (a>b)
    {
        if (c>a) return a;
        if (b>c) return b;
        else return c;
    }
    if (c>b) return b;
    if (a>c) return a;
    else return c;
}

template<typename T>
int average(vector<T> &a, int l, int r)
{
    int i, j, tmp;
    T x = med(a[l+1], a[r-1], a[l+(r-l)/2]);
    j = r+1;
    i = l-1;
    while (1)
    {
      while (a[--j] > x);
      while (a[++i] < x);
      if (i < j)
         swap (a[i], a[j]);
      else
         return j;
   }
}

template<typename T>
void qsort(vector<T> &a, int l, int r, int depth)
{
    if (depth == 0)
        hsort(a, r-l+1, l, r);
    int t;
    if (l<r)
    {
        t = average(a, l, r);
        qsort(a, l, t, depth-1);
        qsort(a, t+1, r, depth-1);
    }
}
