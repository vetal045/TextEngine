#include <iostream>
#include "Console.h"
#include "TextEngine.h"

using namespace std;

int main()
{
	// #####  USING JUST TextEngine ######
	
	auto sumStrings = [](const std::vector<std::string>& strings) -> std::string
	{
		std::string sum;

		for (const std::string &s : strings)
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
	

	//map<string, string> c;

	//c.insert(make_pair<string, string>("1", "2"));

	//auto d = c.find("1");

	//d->second = "3";

	//for (auto i : c)
	//{
	//	cout << i.first << " " << i.second << endl;
	//}

	return 0;
}