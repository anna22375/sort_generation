#include "generation.h"
#include "sort.h"
#include <vector>

int main() {
	std::vector<int> arr;
	random_generate(arr, 10000, 0, 10000, 20, 80);
	sort(arr);
}
