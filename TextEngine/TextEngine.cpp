#include "TextEngine.h"

#include <algorithm>
#include <exception>

namespace TextEngine
{
	TextEngine::TextEngine()
	{
	}

	TextEngine::TextEngine(const TextEngine & te)
	{
		fs = te.getRegisteredFuncs();
	}

	TextEngine & TextEngine::operator=(const TextEngine & other)
	{
		if (&other == this)
		{
			return *this;
		}

		this->fs = other.getRegisteredFuncs();

		return *this;
	}

	void TextEngine::registerFunc(anyFun funs, const std::string & nameFunc)
	{
		fs.insert(std::pair<std::string, anyFun>(nameFunc, funs));
	}

	//void TextEngine::registerFunc(const std::string & nameFunc, const std::vector<std::string>& args_)
	//{
	//	auto sumStrings = [](std::vector<std::string>& strings)
	//	{
	//		std::string sum;

	//		for (std::string s : strings)
	//		{
	//			sum.append(s);
	//		}
	//	};

	//	registerFunc(std::bind(sumStrings, args_), nameFunc);
	//}

	void TextEngine::execFunc(const std::string & nameFunc)
	{
		auto funcToRun = fs.find(nameFunc);

		if (funcToRun != fs.end())
		{
			funcToRun->second();
		}
		else
		{
			std::runtime_error("function is not existed.");
		}
	}

	/*void TextEngine::execFunc(const std::string & nameFunc, const std::vector<std::string>& args_)
	{
		args = args_;

		execFunc(nameFunc);
	}*/

	bool TextEngine::isExistedFunc(const std::string & nameFunc)
	{
		auto func = fs.find(nameFunc);

		return (func != fs.end());
	}

	const funcs TextEngine::getRegisteredFuncs() const
	{
		return fs;
	}
}
