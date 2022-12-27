#include <iostream>
#include <string>

struct IsKPeriodic
{
	auto operator()(std::string const& str, int const K) -> bool
	{
		if (K <= 0 || str.empty() || str.size() <= K || str.size() % K)
			return false;

		for (int i = 0; i < str.size() / (str.size() / K); ++i)
		{
			for (int j = i + K; j < str.size(); j += K)
			{
				if (str[i] != str[j])
				{
					return false;
				}
			}
		}

		return true;
	}
};


auto check() -> void
{
	std::string str("abcabcabcabc");
	std::cout << IsKPeriodic()(str, 3) << std::endl;
	std::cout << IsKPeriodic()(str, 2) << std::endl;
	std::cout << IsKPeriodic()(str, 6) << std::endl;
	std::cout << std::endl;

	str.assign("ababababab");
	std::cout << IsKPeriodic()(str, 2) << std::endl;
	std::cout << IsKPeriodic()(str, 5) << std::endl;
	std::cout << IsKPeriodic()(str, 3) << std::endl;
	std::cout << IsKPeriodic()(str, 0) << std::endl;
	std::cout << std::endl;
}


auto main() -> int
{
	std::cout.setf(std::ios_base::boolalpha);
	check();
	system("pause");
	return EXIT_SUCCESS;
}