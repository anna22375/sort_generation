#include <vector>
#include <algorithm>

template <class T>
void sort(std::vector<T> &array, const int le, const int ri)
{
        if (le >= ri) return;
        int j = partition(array, le, ri);
        sort(array, le, j - 1);
        sort(array, j + 1, ri);
}

template <class T>
void sort(std::vector<T> &array)
{
        static int le = 0;
        static int ri = array.size()-1;
        if (le >= ri) return;
        int j = partition(array, le, ri);
        sort(array, le, j - 1);
        sort(array, j + 1, ri);
}


template <class T>
int partition(std::vector<T> &array, const int le, const int ri)
{
        
        int i = le + 1;
        int j = ri;
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
