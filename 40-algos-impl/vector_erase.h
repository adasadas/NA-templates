#pragma once

// define vector_erase here
#include <vector>

template<typename T>
void vector_erase(T & vec, const typename T::value_type & value)
{
	vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());

}


