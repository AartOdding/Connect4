#pragma once

#include <stdexcept>


namespace utility {

	template<typename T1, typename T2, typename T3>
	bool inside(T1 value, T2 min, T3 max) {
		return value >= min && value <= max;
	}

	template<typename T1, typename T2, typename T3>
	void assert_inside(T1 value, T2 min, T3 max) {
		if(value < min || value > max) throw std::out_of_range("false range assertion");
 	}

	inline void assert_true(bool predicate) {
		if (!predicate) throw std::invalid_argument("assertion failed");
	}

	inline void assert_false(bool predicate) {
		if (predicate) throw std::invalid_argument("assertion failed");
	}

}