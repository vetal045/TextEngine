#include <iostream>
#include "Console.h"
#include "TextEngine.h"

int main()
{
	// #####  USING JUST TextEngine ######

	auto sumStrings = [](std::vector<std::string>& strings) -> std::string
	{
		std::string sum;

		for (std::string s : strings)
		{
			sum.append(s);
		}

		std::cout << sum << std::endl ;

		return sum;
	};


	TextEngine::TextEngine a;

	std::vector<std::string> v = { "Hello" , "Vitalii" };

	a.registerFunc(bind(sumStrings, v), "+");

	a.execFunc("+");

	std::cout << a.getCommandOutput("+") << std::endl;

	std::cout << a.isExistedFunc("+")<< std::endl;

	a.deleteFunc("+");

	std::cout << a.isExistedFunc("+") << std::endl;

	// #####  USING JUST TextEngine ######


	// *****  USING Console *****
	Console cons;

	cons.work();
	// *****  USING Console *****

	return 0;
}