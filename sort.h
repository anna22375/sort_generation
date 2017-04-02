#include <vector>
#include <algorithm>

template <typename T> void heapify (std::vector<T> &arr, int pos, int n) { //принимает на вход позицию корня кучи в массиве и количество элементов в массиве, массив
    while (2 * pos + 1 < n) {
        //пока не вышли за грань массива   
        int t = 2 * pos +1;
        if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
        	//если второй сын существует и больше чем первый

        {
            t = 2 * pos + 2;
        }
        if (arr[pos] < arr[t]) {
        	 // если наибольший из сыновей больше
                // чем предок, то меняем их местами
            std::swap(arr[pos], arr[t]);
            pos = t;  // теперь предком является следующий элемент
        } 
        else break;
        //иначе куча с головой в pos построена
        
    }
}

template <typename T> void heap_make(std::vector<T> &arr, int n) //реализация кучи  // n-количество элементов в массиве
{
    for (int i = n - 1; i >= 0; i--)  // n-количество элементов в массиве
    {
        heapify <T>(arr,i, n);
    }
}
template <typename T> void heap_sort(std::vector<T> &arr) // получение из кучи массива // сама сортировка
{
    int n = arr.size();
    heap_make <T>(arr, n);
    while(n>0)
    {
        std::swap(arr[0],arr[n-1]);
        n--;
        heapify <T>(arr,0,n);
    }
}