#include "counter.h"
#include "generation.h"
#include "sort.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

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

    std::vector<OperationsCounterWrapper<value_t>> wrap_arr(len);
    for(int i = 0; i < len; ++i) wrap_arr[i] = arr[i];

    // sort time measurement
    auto start_time = std::chrono::steady_clock::now();
    heap_sort(arr);
    auto end_time = std::chrono::steady_clock::now();

    if(!std::is_sorted(arr.begin(), arr.end())) {
        std::cout << "Error! Array is not sorted" << std::endl;
        for (int i = arr.size(); i > 0; i--) {
        	std::cout << arr[i] << std::endl;
        }
        return 1;
    }

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    // operations measurement
    OperationsCounterWrapper<value_t>::reset();
    heap_sort(wrap_arr);

    std::cout << " " << (OperationsCounterWrapper<value_t>::comparisons_num
                            + OperationsCounterWrapper<value_t>::assignments_num) / (len * log2(len));

    std::cout << std::endl;

    if(!std::is_sorted(wrap_arr.begin(), wrap_arr.end())) {
        std::cout << "Error! Wrapped array is not sorted" << std::endl;
        return 1;
    }
    return 0;
}
