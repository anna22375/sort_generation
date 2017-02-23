
#include <vector>
template<typename T>
void merge(std::vector<T> &buf, int l, int r, int m);

template<typename T>
void sort(std::vector<T> &arr);

template<typename T>
void MergeSort (std::vector<T>& buf, int l,int r);


template<typename T>
void sort(std::vector<T> &arr) {
    MergeSort(arr, 0, (int) (arr.size() - 1));
}

template<typename T>
void merge(std::vector<T> &buf, int l, int r, int m)
{
    if (l >= r || m < l || m > r) //выходим в случае массива единичной длины
        return;
    if (r == l + 1 && buf[l] > buf[r]) //два массива единичной длины
    {
        std::swap(buf[l], buf[r]);
        return;
    }

    std::vector<T> tmp(&buf[l], &buf[l + r + 1]);

    for (int i = l, j = 0, k = m - l + 1; i <= r; ++i)
    {
        //i - движение по основному массиву
        //j - движение по вспомогательному массиву(левая часть)
        //k - движение по вспомогательному массиву(правая часть)
        if (j > m - l) //если левый массив закончился
        {
            buf[i] = tmp[k++]; //то i эл-т - текущий правый
        }
        else
        if (k > r - l) //если правый массив закончился
        {
            buf[i] = tmp[j++]; //то i эл-т - текущий левый
        }
        else { //левый и правый массивы не закончились
            buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++]; // i эл-т левый меньше правого? да - i = левый, нет - i = правый
        }
    }
}

template<typename T>
void MergeSort(std::vector<T> &buf, int l, int r) {
    if(l >= r) //выход из рекурсии - единичный массив
        return;

    int m = (l + r) / 2;

    MergeSort(buf, l, m); //сортировка левого
    MergeSort(buf, m+1, r); //сортировка правого
    merge(buf, l, r, m); //слияние левого и правого
}