#include <vector>

// repetitions_percent [0, 100] - процент повторений, 0 - все элементы различны
template<typename T>
void generate(std::vector<T> &arr, unsigned long long len, T min_val, T max_val, int repetitions_percent = 0) {
	arr.clear();
	arr.resize(len);
	for (int i = 0; i < len; i++)
		arr[i] = rand() % max_val+min_val;
}

// order_percent [0, 100] - степень упорядоченности, 0 - массив упорядочен по возрастанию
template<typename T>
void shuffle(std::vector<T> &arr, int order_percent) {
}

// Генерация случайной последовательности
template<typename T>
void random_generate(std::vector<T> &arr, unsigned long long len, T min_val, T max_val, int repetitions_percent = 0, int order_percent = 100) {

	// Генерируем упорядоченную последовательность на отрезке [min_val, max_val] с процентом повторений repetitions_percent
	generate<T>(arr, len, min_val, max_val, repetitions_percent);

	// Перемешиваем в зависимости от значения order_percent
	shuffle<T>(arr, order_percent);
}

// Генерация упорядоченной последовательности
template<typename T>
void regular_generate(std::vector<T> &arr, unsigned long long len, T min_val, T max_val, int repetitions_percent = 0, bool sort_ascending = true) {
	// Генерируем упорядоченную последовательность на отрезке [min_val, max_val] с процентом повторений repetitions_percent
	generate<T>(arr, len, min_val, max_val, repetitions_percent);

	// если sort_ascending = false, то меняем порядок
}

// Генерация последовательности (чередование регулярных участков)
template<typename T>
void alternation_generate(std::vector<T> &arr, unsigned long long len, T min_val, T max_val) {
}

// Генерация последовательности (смесь регулярных участков)
template<typename T>
void mixture_generate(std::vector<T> &arr, unsigned long long len, T min_val, T max_val) {
}


