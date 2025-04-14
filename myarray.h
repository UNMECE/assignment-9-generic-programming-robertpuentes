#ifndef myarray_h
#define myarray_h

#include <iostream>
#include <stdexcept>

template <typename t>
class myarray {
private: 
	t* arr;
	std::size_t cap;
	std::size_t len;
	void check_resize() {
		if (len >= cap) {
			std::size_t newcap = (cap == 0) ? 1 : cap * 2;
			t* newarr = new t[newcap];
			for (std::size_t i = 0; i< len; i++){
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			cap = newcap;
		}
	}

public:
	myarray() : arr(nullptr), cap(0), len(0) {}
	~myarray() {
		delete[] arr;
	}
	void addelem(const t& val) {
		check_resize();
		arr[len++] = val;
	}
	t at(std::size_t idx) const {
		if (idx >= len) {
			throw std::out_of_range("index out of range, throwing away");
		}
		return arr[idx];
	}
	std::size_t size() const {
		return len;
	}
	t sum() const {
		t total = 0;
		for (std::size_t i = 0; i < len; i++){
			total += arr[i];
		}
		return total;
	}
	t mini() const {
		if (len == 0) {
			throw std::runtime_error("array is empty, no min");
		}
		t m = arr[0];
		for (std::size_t i = 1; i < len; ++i) {
			if (arr[i] < m) {
                	m = arr[i];
            		}
        	}
		return m;
	}
	t maxi() const {
		if (len == 0) {
			throw std::runtime_error("array is empty");
		}
		t m = arr[0];
		for (std::size_t i = 1; i < len; i++){
			if (arr[i] > m) {
				m = arr[i];
			}
		}
		return m;
	}
	myarray<t> slice(std::size_t start, std::size_t end) const {
		if (start > end || end > len) {
			throw std::out_of_range("slice out of range");	
		}
		myarray<t> result;
		for (std::size_t i = start; i < end; i++){
			result.addelem(arr[i]);
		}
		return result;
	}
};

#endif

