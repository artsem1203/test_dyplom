#pragma once
#include <iostream>
template<typename T>
class Memory {
public:
	Memory(size_t chunk_size) : size_(chunk_size) {
		memory_pointer_ = new T[size_];
	}

	~Memory() {
		delete[] memory_pointer_;
	}
	void add_value(T val) {
		memory_pointer_[counter_++] = val;
	}
	void show() {
		for (size_t i = 0; i < size_; i++) {
			std::cout << memory_pointer_[i] << std::endl;
		}
	}
private:
	T* memory_pointer_;
	size_t size_;
	size_t counter_ = 0;
};
