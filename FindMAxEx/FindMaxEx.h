#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMax(const std::vector<T> & vec, T& maxValue, const Less & less)
{
	if (vec.empty())
	{
		return false;
	}
	T max = vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (less(max, vec[i]))
		{
			max = vec[i];
		}
	}
	maxValue = max;
	return true;
};