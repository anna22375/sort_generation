#include <vector>
#include <algorithm>

template <class T>
void sort(std :: vector<T> &array, const int le, const int ri)
{
        if (le >= ri) return;
        int j = partition(array, le, ri);
        sort(array, le, j - 1);
        sort(array, j + 1, ri);
}

template <class T>
void sort(std :: vector<T> &array)
{
        sort(array, 0, array.size() - 1);
}

int median(const int a, const int b, const int c)
{
        if (a < b) {
                if (b < c)
                        return b;
                else if (a < c) //a < b, b >= c
                        return c;
                else return a; //a < b, b >=c, a >= c
        }
        else //a >= b
        {
                if (a < c)
                        return a;
                else if (b < c) //a >= b, a >= c, b < c
                        return c;
                else return b; // a >= b, a >= c, b >= c
        }
}

template <class T>
int partition(std :: vector<T> &array, const int le, const int ri)
{

        int reference = median(le + 1, le + (ri - le) / 2, ri - 1);
        int i = le + 1;
        int j = ri;
        swap(array[le], array[reference]);

        while (i <= j)
        {
                if (array[i] < array[le]) i++;
                else if (array[j] > array[le]) j--;
                else {
                        swap(array[i], array[j]);
                        i++;
                        j--;
                }
        }
        swap(array[j], array[le]);
        return j;
}
