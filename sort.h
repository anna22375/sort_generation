#include <vector>
#include <algorithm>

int median(std::vector<T> &array, const int le, const int ri)
{
        if (array[le + 1] < array[le + (ri - le) / 2]) {
                if (array[le + (ri - le) / 2] < array[ri - 1])
                        return le + (ri - le) / 2;
                else if (array[le + 1] < array[ri - 1]) //a < b, b >= c
                        return ri - 1;
                else return le + 1; //a < b, b >=c, a >= c
        }
        else //a >= b
        {
                if (array[le + 1] < array[ri - 1])
                        return le + 1;
                else if (array[le + (ri - le) / 2] < array[ri - 1]) //a >= b, a >= c, b < c
                        return ri - 1;
                else return le + (ri - le) / 2; // a >= b, a >= c, b >= c
        }
}

template <class T>
int partition(std::vector<T> &array, le, ri)
{

        int reference = median(le + 1, le + (ri - le) / 2, ri - 1);
        int i = le + 1;
        int j = ri;
        std::swap(array[le], array[reference]);

        while (i <= j)
        {
                if (array[i] < array[le]) i++;
                else if (array[j] > array[le]) j--;
                else {
                        std::swap(array[i], array[j]);
                        i++;
                        j--;
                }
        }
        std::swap(array[j], array[le]);
        return j;
}

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
        sort(array, 0, array.size() - 1);
}
