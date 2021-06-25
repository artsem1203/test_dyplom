#pragma once
#include <array>
#include "Memory.h"
#include "Dimentions.h"
#include "Handler.h"


template<typename T, size_t N>
class Data{
public:

	Data() = delete;

	template<typename ...Dims>
	Data(Dims ... dims): dims_(dims...), memr_(dims_.size_calc()) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
	}

	size_t size_calc() const {
		return dims_.size_calc();
	}

	void init(const std::initializer_list<T> init_list) {
		for (auto i = std::cbegin(init_list); i != std::cend(init_list); i++) {
			memr_.add_value(*i);
		}
	}

	void show() {
		this->memr_.show();
	}

private:
	T* data_;
	Dimentions<N> dims_;
	Memory<T> memr_;
};

