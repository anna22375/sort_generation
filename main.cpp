#include "generation.h"
#include "sort.h"
#include "op_counter.h"
#include <vector>
#include <chrono>
#include <iostream>

int main() {
	using value_t = double;

	std::vector<value_t> arr;
	random_generate(arr, 10000, value_t(0), value_t(10000), 20, 80);

	auto start_time = std::chrono::steady_clock::now();
	sort(arr);
	auto end_time = std::chrono::steady_clock::now();

	std::cout << "sort time: " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " ms." << std::endl;

	std::vector<OperationsCounterWrapper<value_t>> wrap_arr;
	random_generate(wrap_arr, 10000, OperationsCounterWrapper<value_t>(0), OperationsCounterWrapper<value_t>(10000), 20, 80);

	OperationsCounterWrapper<value_t>::reset();

	sort(wrap_arr);
	std::cout << "assignments: " << OperationsCounterWrapper<double>::assignments_num << std::endl;
	std::cout << "comparisons: " << OperationsCounterWrapper<double>::comparisons_num << std::endl;
}
