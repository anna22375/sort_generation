#include <vector>
#include <cstdlib>
#include <algorithm>

// repetitions_percent [0, 100] - процент повторений, 0 - все элементы различны
template<typename T>
void generate(std::vector<T> &arr, size_t len, T min_val, T max_val, int repetitions_percent = 0) {
	arr.clear();
	arr.resize(len);

	const auto mapping_factor = (max_val - min_val) / ((100 - repetitions_percent) / 100.0 * len);

	for (size_t i = 1; i < len; i++) {
		arr[i] = (arr[i - 1] + (std::rand() % 100 + 1 > repetitions_percent ? 1 : 0));
		arr[i - 1] = arr[i - 1] * mapping_factor + min_val; // отображение на отрезок
	}
	arr[len - 1] = arr[len - 1] * mapping_factor + min_val;
}

// order_percent [0, 100] - степень упорядоченности, 0 - массив упорядочен по возрастанию
template<typename T>
void shuffle(std::vector<T> &arr, int order_percent) {
	std::random_shuffle (arr.begin(), arr.end());
}

// Генерация случайной последовательности
template<typename T>
void random_generate(std::vector<T> &arr, size_t len, T min_val, T max_val, int repetitions_percent = 0, int order_percent = 100) {

	// Генерируем упорядоченную последовательность на отрезке [min_val, max_val] с процентом повторений repetitions_percent
	generate<T>(arr, len, min_val, max_val, repetitions_percent);

	// Перемешиваем в зависимости от значения order_percent
	shuffle<T>(arr, order_percent);
}

// Генерация упорядоченной последовательности
template<typename T>
void regular_generate(std::vector<T> &arr, size_t len, T min_val, T max_val, int repetitions_percent = 0, bool sort_ascending = true) {
	// Генерируем упорядоченную последовательность на отрезке [min_val, max_val] с процентом повторений repetitions_percent
	generate<T>(arr, len, min_val, max_val, repetitions_percent);

	// если sort_ascending = false, то меняем порядок
}

// Генерация последовательности (чередование регулярных участков)
template<typename T>
void alternation_generate(std::vector<T> &arr, size_t len, T min_val, T max_val) {
        arr.clear();
	arr.resize(len+1);
	size_t the_number_of_parts = 1 + rand() % (len / 10);
	size_t amount_of_numbers = len;
	for (size_t i = 1; i <= len; i++)
	{ 

		T first_val = min_val;
		if (the_number_of_parts != 1) 
			amount_of_numbers = 1 + rand() % (amount_of_numbers - the_number_of_parts);
		size_t k = i;
		for (size_t j = i; j <k+amount_of_numbers; j++)
		{
			arr[j] = first_val + rand() % (max_val - first_val + 1);
			first_val = arr[j];
			i++;
		}
		i--;
		the_number_of_parts--;
		amount_of_numbers = len - i;
	}
}

// Генерация последовательности (смесь регулярных участков)
template<typename T>
void mixture_generate(std::vector<T> &arr, size_t len, T min_val, T max_val) {
}


