#ifndef OP_COUNTER_H
#define OP_COUNTER_H

// http://www.cs.rpi.edu/~musser/gp/code/counter.h.txt

using op_num_t = unsigned long long;

template <typename T>
class OperationsCounterWrapper {

public:
	static op_num_t assignments_num;
	static op_num_t comparisons_num;

	static void reset() {
		assignments_num = 0;
		comparisons_num = 0;
	}

	OperationsCounterWrapper() = default;

	OperationsCounterWrapper(const T& val) : value_(val) {
		++assignments_num;
	}

	OperationsCounterWrapper(const OperationsCounterWrapper<T>& v) : value_(v.value_) {
		++assignments_num;
	}

	OperationsCounterWrapper<T>& operator=(const OperationsCounterWrapper<T>& r) {
		++assignments_num;
		value_ = r.value_;
		return *this;
	}

	T value() const { return value_; }

private:
	T value_;
};

template<typename T>
bool operator< (const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) {
    OperationsCounterWrapper<T>::comparisons_num++;
    return l.value() < r.value();
}

template<typename T>
bool operator> (const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) { return r < l; }

template<typename T>
bool operator<=(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) { return !(l > r); }

template<typename T>
bool operator>=(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) { return !(l < r); }

template<typename T>
bool operator==(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) {
    OperationsCounterWrapper<T>::comparisons_num++;
    return l.value() == r.value();
}

template<typename T>
bool operator!=(const OperationsCounterWrapper<T>& l, const OperationsCounterWrapper<T>& r) { return !(l == r); }

template <typename T>
op_num_t OperationsCounterWrapper<T>::assignments_num = 0;

template <typename T>
op_num_t OperationsCounterWrapper<T>::comparisons_num = 0;

#endif

