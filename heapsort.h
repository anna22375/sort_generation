//функции 

const int NMAX = 100000;
int arr[NMAX + 1];

void heapify(int *arr, int pos, int n);//нормализация кучи
//void heap_push(int *arr, int v);//добавление элемента в кучу
					//принимает на вход номер элемента в массиве,
					 //который необходимо добавить в кучу
void heap_make(int *arr, int n);//функция построения кучи
void heap_sort(int *arr, int n);//сортировка