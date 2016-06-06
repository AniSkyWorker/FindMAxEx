#include "stdafx.h"
#include "../FindMAxEx/FindMaxEx.h"

struct Athlete
{
	Athlete()
		:name(), height(0), weight(0) {};
	Athlete(const std::string & name, int height, int weight)
		:name(name), height(height), weight(weight) {};
	std::string name;
	int height;
	int weight;
};

BOOST_AUTO_TEST_SUITE(FindMax_)

	BOOST_AUTO_TEST_CASE(have_strong_exception_safety)
	{
		std::vector<int> vec = { -11, 2, 5, 4, 5 };
		auto func = [&](const auto & num1, const auto & num2)
		{
			if (num1 == 4 || num2 == 4)
				{
					throw std::runtime_error("Error: element == 4!");
				}
				return num1 < num2;
			};

		auto max = 0;
		BOOST_REQUIRE_THROW(FindMax(vec, max, func), std::runtime_error);
		BOOST_CHECK_EQUAL(max, 0);
	}

	BOOST_AUTO_TEST_CASE(uses_binary_predicate_as_search_strategy)
	{
		std::vector<Athlete> athlets;

		Athlete onEmpty;
		auto empty = FindMax(athlets, onEmpty, [&](auto const& s1, auto const& s2)
		{
			return s1.weight < s2.weight;
		});
		BOOST_CHECK_EQUAL(onEmpty.name, ""); 

		athlets =
		{
			Athlete("Ahill", 165, 71),
			Athlete("Minos", 170, 90),
			Athlete("Sumo", 181, 60),
			Athlete("Everest", 181, 79),
			Athlete("Locomotiv", 179, 90)
		};

		Athlete highest;
		auto byHight = FindMax(athlets, highest, [&](const auto & s1, const auto & s2)
		{
			return s1.height < s2.height;
		});
		BOOST_CHECK_EQUAL(highest.name, athlets[2].name);

		Athlete heaviest;
		auto byHeavy = FindMax(athlets, heaviest, [&](const auto & s1, const auto & s2)
		{
			return s1.weight < s2.weight;
		});
		BOOST_CHECK_EQUAL(heaviest.name, athlets[1].name);
	}

BOOST_AUTO_TEST_SUITE_END()