#pragma once
#include "Dimentions.h"
#include "Memory.h"

template<typename T, size_t N>
class Handler
{
	Handler() {

	}
	size_t size_calc() const {
		return dims_.size_calc();
	}
private:

	T* data_;
	Dimentions<N> dims_;
	Memory<T> memr_;
};

