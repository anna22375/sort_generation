#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <cstdlib>
#include <algorithm>

// ordered sequence generation
template<typename T>
void regular_generate(std::vector<T> &arr, int len, int distinct, bool ascending = true) {
    arr.clear();
    arr.resize(len);

    for(int i = 0; i < len; ++i) arr[i] = rand() % distinct;

    if(ascending)
        std::sort(arr.begin(), arr.end());
    else
        std::sort(arr.begin(), arr.end(), [] (const T& a, const T& b) {return a > b;});
}

// shuffle
template<typename T>
void shuffle(std::vector<T> &arr, int disorder) {

    if(disorder == 0) return;

    int size = arr.size();
    for (int i = 1; i < size; i++) {
        if(rand() % 100 < disorder)
            std::swap(arr[i], arr[rand() % i]);
	}
}

// random sequence generation
template<typename T>
void random_generate(std::vector<T> &arr, int len, int distinct, int disorder = 100) {

    regular_generate<T>(arr, len, distinct);
    shuffle<T>(arr, disorder);
}

// alternation of ordered segments
template<typename T>
void alternation_generate(std::vector<T> &arr, int len) {

    random_generate(arr, len, len, 100);

    int start = 0;
    int finish = std::max(10, std::min(rand() % len, 100));

    while(finish < len) {
        std::sort(arr.begin() + start, arr.begin() + finish);

        start = finish;
        finish += std::max(10, std::min(rand() % len, 100));
    }

    std::sort(arr.begin() + start, arr.end());
}

#endif // GENERATION_H

