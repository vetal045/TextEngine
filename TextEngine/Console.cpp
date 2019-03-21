#include "Console.h"
#include "AvailableFunctions.h"

#include <sstream>

using namespace std::placeholders;

Console::Console()
{
}

void Console::work()
{
	while (true)
	{
		std::cout << "&:";

		std::stringstream ss;
		std::string s, out, command;

		std::getline(std::cin, s);

		ss << s;

		while (ss >> out)
		{
			args.push_back(out);
		}

		if (!args.empty())
		{
			command = getCommand(args);

			for (auto s : args)
			{
				std::cout <<"!!!"<< s << " ";
			}
		}

		if (command == "+")
		{
			addFunc("+", std::bind(Function::sum, args));

			te.execFunc(command);

			te.deleteFunc(command);

			args.clear();

			continue;
		}
		
		if (command == "q")
		{
			break;
		}

		if (command == "help")
		{
			std::cout << "============================================================" << std::endl;
			std::cout << "Example of using command line: 'command' {par: ' ' ' ' ...}" << std::endl;
			std::cout << "+ hello vitalii \n" << std::endl;
			std::cout << "NOTE: development is still ongoing..." << std::endl;
			std::cout << "============================================================" << std::endl;

			continue;
		}

		std::cout << "Unknown command." << std::endl;

		command = "";
		std::cout.flush();
		args.clear();
	}
}

void Console::addFunc(const std::string nameFunc, TextEngine::anyFun func)
{
	te.registerFunc(func, nameFunc);
}

const std::string Console::getCommand(std::vector<std::string>& args_)
{
	std::string command;

	if (!args_.empty())
	{
		command = args_.front();
		args_.erase(args_.begin());
	}

	return command;
}
