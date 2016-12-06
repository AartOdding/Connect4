#pragma once


namespace utility {

	template<typename T1, typename T2, typename T3>
	bool inside(T1 value, T2 min, T3 max) {
		return value >= min && value <= max;
	}

}