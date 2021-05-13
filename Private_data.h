#pragma once
#include <iostream>
#include <type_traits>
#include <typeinfo>

template <typename T, int M, int N>
class Private_data
{
private:
	T **p_data;
public:
	Private_data() {
		p_data = new T * [M];
		for (int i = 0; i < M; i++)
			p_data[i] = new T[N];
		
		
	}
	
	void test_init() {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				p_data[i][j] = i + j;
			}
		}
	}
	
	void show() {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				std::cout << i << " " << j << " element: " << p_data[i][j] << std::endl;
			}
		}
	}

	const T *return_column(int index) const {
		return p_data[index];
	}
	
	~Private_data() {
		for (int i = 0; i < M; i++)
			delete[] p_data[i];
		delete[] p_data;
	}

};

