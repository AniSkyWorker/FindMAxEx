#pragma once
#include <vector>

template <typename T, typename Less>
bool FindMax(const std::vector<T> & vec, T& maxValue, const Less & less)
{
	if (vec.empty())
	{
		return false;
	}

	auto max = vec.begin();
	for (auto it = vec.begin() + 1; it != vec.end(); ++it)
	{
		if (less(*max, *it))
		{
			max = it;
		}
	}
	maxValue = *max;
	return true;
};