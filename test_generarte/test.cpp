#include <gtest/gtest.h>
#include "../generation.h"
#include "test_utils.h"

#include <fstream>

TEST(RandomGenerateTest, CheckULLParams) {
	std::vector<unsigned long long> arr;

	std::ifstream in("generate_tests.txt");
	int test_num;
	in >> test_num;

	SeqParams<unsigned long long> params, res_params;

	for (int i = 0; i < test_num; ++i) {
		in >> params;
		
		generate(arr, params.len, params.min_val, params .max_val, params.repetitions_percent);
		std::cerr << params.len << " " << params.min_val << " " << params .max_val << " " << params.repetitions_percent << std::endl;
		res_params = calcRepetitionsPercent(arr);

		EXPECT_LE(params.min_val, res_params.min_val);
		EXPECT_GE(params.max_val, res_params.max_val);
		EXPECT_LE(abs(params.repetitions_percent - res_params.repetitions_percent), 10);
	}
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
