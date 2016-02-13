#ifndef OP_COUNTER_H
#define OP_COUNTER_H

// http://www.cs.rpi.edu/~musser/gp/code/counter.h.txt

#include <utility>

using op_num_t = unsigned long long;

template <typename T>
class OperationsCounterWrapper {

public:
	static op_num_t assignments_num;
	static op_num_t comparisons_num;

	OperationsCounterWrapper() = default;

	explicit OperationsCounterWrapper(const T& val) : value_(val) {
		++assignments_num;
	}

	OperationsCounterWrapper(const OperationsCounterWrapper<T>& v) : value_(v.value_) {
		++assignments_num;
	}

	bool operator<(const OperationsCounterWrapper<T>& r) {
		++comparisons_num;
		return value_ < r.value_;
	}

	OperationsCounterWrapper<T>& operator=(const T& val) {
		++assignments_num;
		value_ = val;
		return *this;
	}

	OperationsCounterWrapper<T>& operator=(const OperationsCounterWrapper<T>& r) {
		++assignments_num;
		value_ = r.value_;
		return *this;
	}

	static void reset() {
		assignments_num = 0;
		comparisons_num = 0;
	}

	T value() const { return value_; }
private:
	T value_;
};

template<typename T>
auto operator+(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r)
	-> decltype(std::declval<T>() + std::declval<T>()) {
	return l.value() + r.value();
}

template<typename T, typename U>
auto operator+(const OperationsCounterWrapper<T>& l, const U& r)
	-> decltype(std::declval<T>() + std::declval<U>()) {
	return l.value() + r;
}

template<typename T, typename U>
auto operator+(const U& l, const OperationsCounterWrapper<T>& r)
	-> decltype(std::declval<U>() + std::declval<T>()) {
	return l + r.value();
}

template<typename T>
auto operator-(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r)
	-> decltype(std::declval<T>() - std::declval<T>()) {
	return l.value() - r.value();
}

template<typename T, typename U>
auto operator-(const OperationsCounterWrapper<T>& l, const U& r)
	-> decltype(std::declval<T>() + std::declval<U>()) {
	return l.value() - r;
}

template<typename T, typename U>
auto operator-(const U& l, const OperationsCounterWrapper<T>& r) 
	-> decltype(std::declval<U>() + std::declval<T>()) {
	return l - r.value();
}

template<typename T, typename U>
auto operator*(const OperationsCounterWrapper<T>& l, const U& r)
	-> decltype(std::declval<T>() * std::declval<U>()) {
	return l.value() * r;
}

template<typename T, typename U>
auto operator/(const OperationsCounterWrapper<T>& l, const U& r)
	-> decltype(std::declval<T>() / r) {
	return l.value() / r;
}

template <typename T>
op_num_t OperationsCounterWrapper<T>::assignments_num = 0;

template <typename T>
op_num_t OperationsCounterWrapper<T>::comparisons_num = 0;

#endif

