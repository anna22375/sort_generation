#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

template<typename T>
void sort(std::vector<T> &arr) {

	auto start_time = std::chrono::steady_clock::now(); // тип t1 - std::chrono::steady_clock::time_point

	for (size_t i = 0; i < arr.size() - 1; i++){
		size_t position_min = i;
		for (size_t j = i + 1; j < arr.size(); j++){
			if (arr[j] < arr[position_min]) {
				position_min = j;
			}
		}
		std::swap(arr[i], arr[position_min]);
	}

	auto end_time = std::chrono::steady_clock::now();

	std::cout << "sort time: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " ms." << std::endl;
}
