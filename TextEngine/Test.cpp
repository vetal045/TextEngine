#include <iostream>
#include "Console.h"
#include "TextEngine.h"

using namespace std;

int main()
{
	try
	{
		

		// #####  USING JUST TextEngine ######

		using Args = vector<string>;

		auto sumStrings = [](const Args& strings) -> std::string
		{
			std::string sum;

			for (const std::string &s : strings)
			{
				sum.append(s);
			}

			return sum;
		};

		TextEngine::TextEngine a;

		std::vector<std::string> v{ "fsdf", "asfa" };

		a.registerFunc("+", sumStrings);

		a.execFunc("+", { "2", "3" });
		std::cout << a.getCommandOutput("+") << std::endl;
		std::cout << a.isExistedFunc("+") << std::endl;

		a.execFunc("+", v);
		std::cout << a.getCommandOutput("+") << std::endl;

		// #####  USING JUST TextEngine ######


		// *****  USING Console *****

		Console cons;
		cons.setTextEngine(a);
		cons.work();

		// *****  USING Console *****
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error is - " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown error." << std::endl;
	}
	
	return 0;
}