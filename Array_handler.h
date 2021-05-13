#pragma once
#include <iostream>
#include "Private_data.h"


template <typename T, int N>
class Array_handler
{
private:
	T* h_column;
	T* buffer;
public:
	Array_handler() {
		
		buffer = new T[N];
		for (int i = 0; i < N; i++) {
			buffer[i] = i * 10;
		}
		h_column = nullptr;
		
	}

	void show() {
		for (int i = 0; i < N; i++) {
			std::cout << i << " element: " << h_column[i] << std::endl;
		}
	}
	
	void test_change() {
		for (int i = 0; i < N; i++) {
			h_column[i]++;
		}
	}

	void take_column(const T *column) {
		//h_column = column;
		h_column = new T[N];
		for (int i = 0; i < N; i++) {
			h_column[i] = column[i];
		}
	}
	
	void take_column(T* column) {
		h_column = column;
	}

	~Array_handler() {
		delete[] buffer;
		delete[] h_column;
	}
};

