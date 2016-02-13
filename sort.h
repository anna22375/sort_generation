#include <vector>
#include <algorithm>

template<typename T>
void sort(std::vector<T> &arr, (bool) compare(T a, T b) ) {
	for (size_t i = 0; i < arr.size() - 1; i++){
		size_t position_min = i;
		for (size_t j = i + 1; j < arr.size(); j++){
			if (compare(arr[j], arr[position_min]) == true  ) {
			//if (arr[j] < arr[position_min]) {
				position_min = j;
			}
		}
		std::swap(arr[i], arr[position_min]);
	}
}

template<typename T>
bool compare(T a, T b)
{
	if (a< b) return 1;
	else return 0;
}
