#pragma once

#include <random>
#include <type_traits>

#define RND Lib::rnd::ptr()

namespace Lib {

	using namespace std;

	class rnd
	{
		random_device rd;
		mt19937 gen;
		rnd();
	public:
		static rnd& ptr();
		template<typename Type>
		enable_if_t<is_arithmetic_v<Type>,Type>
			range(Type from, Type to) {
			if constexpr (is_integral_v<Type>)
				return uniform_int_distribution(from, to)(gen);
			else
				return uniform_real_distribution(from, to)(gen);
		}
	};
}