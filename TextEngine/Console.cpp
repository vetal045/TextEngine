#include "Console.h"

#include <sstream>

Console::Console()
{
}

void Console::work()
{
	//some functions
	//***
	auto sum = [](std::vector<std::string>& strings)
	{
		std::string sum;

		for (std::string s : strings)
		{
			sum.append(s);
		}

		std::cout << sum << std::endl;
	};
	//***

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
		}

		te.registerFunc(std::bind(sum, args), "+");

		if (te.isExistedFunc(command))
		{
			//that part should be changed during future development
			//***
			//te.registerFunc(command, args);
			//***

			te.execFunc(command);

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
