#include <vector>
#include <algorithm>

template <typename T>
void pileFormation (std::vector <T> &arr, int root, int max)
{
    int maxChild = 0;
    int flag     = 0;
    
    while ((root * 2 <= max) && (!flag))
    {
        if (root * 2 == max) maxChild = root * 2;
        
        else if (arr[root * 2] > arr[root * 2 + 1]) maxChild = root * 2;
        
        else maxChild = root * 2 + 1;
        
        if (arr[root] < arr[maxChild])
        {
            T tmp = arr[root];
            
            arr[root] = arr[maxChild];
            arr[maxChild] = tmp;
            
            root = maxChild;
        }
        
        else flag = 1;
    }
}

template<typename T>
void sort (std::vector<T> &arr)
{
    for (int i = (arr.size() / 2) - 1; i >= 0; i--) pileFormation <T> (arr, i, arr.size());
    
    for (int i = arr.size() - 1; i >= 1; i--)
    {
        T tmp = arr[0];
        
        arr[0] = arr[i];
        arr[i] = tmp;
        
        pileFormation <T> (arr, 0, i - 1);
    }
}
