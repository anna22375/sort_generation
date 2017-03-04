#include <vector>
#include <algorithm>

template <typename T>
int partition(std::vector<T> &a, const int l, const int r)
{
        int j = (l + r) / 2;
        if (a[j] > a[l])
                if (a[j] > a[r])
                        if (a[l] > a[r])
                                std::swap(a[l], a[l]);
                        else std::swap(a[l], a[r]);
                else std::swap(a[l], a[j]);
        else
                if (a[j] < a[r])
                        if (a[l] < a[r])
                                std::swap(a[l], a[l]);
                        else std::swap(a[l], a[r]);
                else std::swap(a[l], a[j]);

                j = l;
                for (int i = l + 1; i <= r; i++)
                        if (a[i] < a[l])
                        {
                                j++; std::swap(a[j], a[i]);
                        }
                std::swap(a[l], a[j]);
                return j;
}

template <typename T>
void sift(std::vector<T> &a, int l, int r)
{
        int i = l;
        int j = 2 * i;
        T y = a[i];
        while (j <= r) //i - номер текущего места y
                                   //j - номер левого "опорного" элемента
        {
                if (j < r)			//оба "опорных" входят в массив
                        if (a[j] < a[j + 1])
                                j++;	//выбрали max из "опорных"
                if (y >= a[j]) break;		//встали на место
                                                                        //идем "вниз":
                a[i] = a[j];
                i = j;
                j = 2 * i;
        }
        a[i] = y;
}

template <typename T>
void heapSort(std::vector<T> &a)
{
        int n = a.size() - 1;
        // n - номер последнего элемента (массив [1..n])
        // фаза 1: формирование пирамиды
        for (int i = (n / 2); i > 0; i--)
                sift(a, i, n);
        // фаза 2: полное упорядочение
        for (int i = n; i > 1; i--)
        {
                swap(a[1], a[i]);
                sift(a, 1, i - 1);
        }
}

template <typename T>
void sort(std::vector<T> &a, const int l, const int r)
{
        if (l >= r) return;
        int j = partition(a, l, r);

        if ((j - l) > 16)
                sort(a, l, j - 1);
        else
                heapSort(a);

        if ((r - j) > 16)
                sort(a, j + 1, r);
        else
                heapSort(a);
}
