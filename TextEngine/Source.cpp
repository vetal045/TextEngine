#include <iostream>
#include "Console.h"
#include "TextEngine.h"

#include <sstream>

using namespace std;

typedef std::function<void(void)> fun_t;
std::map<std::string, fun_t> funs;

void exec(fun_t a)
{
	a();
}


void Output(fun_t f) {
	f();
	std::cout << std::endl;
}

template<typename First, typename ... Strings>
void Output(fun_t f, First arg, const Strings&... rest) {
	std::cout << arg << " ";
	Output(f, rest...);
	
}

void f(fun_t f, std::string s, std::vector<std::string> args)
{

};

int main()
{
	auto sumStrings = [](std::vector<std::string>& strings)
	{
		std::string sum;

		for (std::string s : strings)
		{
			sum.append(s);
		}

		std::cout << sum << std::endl ;
	};


	TextEngine::TextEngine a;

	std::vector<std::string> v = { "Hello" , "Vitalii" };
	a.registerFunc(std::bind(sumStrings, v), "+");

	TextEngine::TextEngine b;

	b = a;

	//b.execFunc("+");
	//std::cout << b.isExistedFunc("-");

	Console cons;

	cons.work();

	return 0;
}