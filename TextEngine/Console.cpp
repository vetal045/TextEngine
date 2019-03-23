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

		std::string s, out, command;

		std::getline(std::cin, s);

		std::stringstream ss(s);

		while (ss >> out)
		{
			args_.push_back(out);
		}

		if (!args_.empty())
		{
			command = getCommand(args_);
		}

		if (te_.isExistedFunc(command))
		{
			//addFunc("+", std::bind(Function::sum, args_));

			te_.execFunc(command, args_);

			std::cout << te_.getCommandOutput(command) << std::endl;

			//te_.deleteFunc(command);

			args_.clear();

			continue;
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

		if (command == "q")
		{
			break;
		}

		std::cout << "Unknown command." << std::endl;

		std::cout.flush();
		args_.clear();
	}
}

void Console::addFunc(const std::string nameFunc, TextEngine::anyFun func)
{
	te_.registerFunc(nameFunc, func);
}

void Console::setTextEngine(const TextEngine::TextEngine & te)
{
	te_ = te;
}

TextEngine::TextEngine Console::getTextEngine() const
{
	return te_;
}

const std::string Console::getCommand(std::vector<std::string>& args)
{
	std::string command;

	if (!args.empty())
	{
		command = args.front();
		args.erase(args.begin());
	}

	return command;
}
