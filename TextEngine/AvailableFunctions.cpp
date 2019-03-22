#include "AvailableFunctions.h"

namespace Function
{
	const std::string sum(std::vector<std::string> args)
	{
		std::string sum;

		if (!args.empty())
		{
			for (std::string s : args)
			{
				sum.append(s);
			}
		}

		return sum;
	}
}
