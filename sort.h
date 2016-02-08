#include <vector>

template<typename T>
void sort(std::vector<T> &arr) {
  	for (int i = 0; i < arr.size() - 1; i++){
		int position_min = i;
		for (int j = i + 1; j < arr.size(); j++){
			if (arr[j] < arr[position_min]) {
				position_min = j;
			}
		}
		T temp;
		temp = arr[i];
		arr[i] = arr[position_min];
		arr[position_min] = temp;
	}
}
