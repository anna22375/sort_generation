#include "generation.h"
#include "counter.h"
#include "sort.h"
#include <ctime>
#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>

int main(int argc, char **argv) {

    using value_t = int;

    if(argc < 3) {
        std::cerr << "Usage: <array len> <generate type> <generate options>" << std::endl;
        exit(EXIT_FAILURE);
    }

    int len = atoi(argv[1]);

    std::vector<value_t> arr;

    srand(time(0));

    std::string gen_type(argv[2]);
    if(gen_type == "regular") {

        if(argc != 5) {
            std::cerr << "Usage: <array len> regular <distinct> <ascending>" << std::endl;
            exit(EXIT_FAILURE);
        }

        regular_generate(arr, len, atoi(argv[3]), atoi(argv[4]) != 0);

    } else if(gen_type == "random") {

        if(argc != 5) {
            std::cerr << "Usage: <array len> random <distinct> <disorder>" << std::endl;
            exit(EXIT_FAILURE);
        }

        random_generate(arr, len, atoi(argv[3]), atoi(argv[4]));

    } else if(gen_type == "alternation") {

        if(argc != 3) {
            std::cerr << "Usage: <array len> alternation" << std::endl;
            exit(EXIT_FAILURE);
        }

        alternation_generate(arr, len);
    }

    // sort time measurement
	auto start_time = std::chrono::steady_clock::now();
	sort(arr);
	auto end_time = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    // operations measurement
    std::vector<OperationsCounterWrapper<value_t>> wrap_arr(len);
    for(int i = 0; i < len; ++i) wrap_arr[i] = arr[i];

	OperationsCounterWrapper<value_t>::reset();
	sort(wrap_arr);

    std::cout << " " << OperationsCounterWrapper<value_t>::assignments_num / (len * log2(len));
    std::cout << " " << OperationsCounterWrapper<value_t>::comparisons_num / (len * log2(len));
    std::cout << std::endl;
}
