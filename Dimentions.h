#pragma once
#include <array>

template <size_t N>
class Dimentions
{
public:
	template<typename ...Dims>
	Dimentions(Dims ... dims) {
		static_assert(sizeof...(Dims) <= N, "Wrong number of parameters");
		std::initializer_list<size_t> init_list{ size_t(dims)... };

		int counter = 0;
		for (auto i = std::cbegin(init_list); i != std::cend(init_list); i++, counter++) {
			dims_[counter] = *i;
		}
	}

	size_t size_calc() const {
		size_t temp = 1;
		for (auto i = dims_.cbegin(); i != dims_.cend(); i++) {
			temp = temp * (*i);
		}
		return temp;
	}

private:
	std::array<size_t, N> dims_;
};

