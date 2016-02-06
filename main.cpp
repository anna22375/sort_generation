#include "generation.h"
#include "sort.h"
#include <vector>

int main() {
	std::vector<int> arr;
	random_generate(arr, 10, 0, 10, 50, 80);
	sort(arr);
}
