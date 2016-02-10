#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
struct SeqParams {
	unsigned long long len;
	T min_val;
	T max_val;
	int repetitions_percent;

	friend std::istream& operator>>(std::istream& in, SeqParams<T>& p)
	{
		in >> p.len >> p.min_val >> p.max_val >> p.repetitions_percent;
		return in;
	}
};

template<typename T>
SeqParams<T> calcRepetitionsPercent(const std::vector<T> &arr) {
	std::vector<T> sorted_arr(arr.begin(), arr.end());
	std::sort(sorted_arr.begin(), sorted_arr.end());

	unsigned long long repetitions_num = 0;
	for (unsigned long long i = 1; i < arr.size(); ++i) {
		if (arr[i] == arr[i-1])
			repetitions_num++;
	}

	return {sorted_arr.size(), sorted_arr[0],
			sorted_arr[sorted_arr.size() - 1],
			int(repetitions_num * 100.0 / sorted_arr.size())};
}
