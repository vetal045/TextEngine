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

	void TextEngine::deleteFunc(const std::string & nameFunc)
	{
		if (isExistedFunc(nameFunc))
		{
			fs.erase(fs.find(nameFunc));
		}
		else 
		{
			std::runtime_error("function is not existed.");
		}
	}

	void TextEngine::execFunc(const std::string & nameFunc)
	{
		if (isExistedFunc(nameFunc))
		{
			auto funcToRun = fs.find(nameFunc);

			auto result = funcToRun->second();

			setCommandOutput(nameFunc, result);
		}
		else
		{
			std::runtime_error("function is not existed.");
		}
	}

	void TextEngine::setCommandOutput(const std::string nameFunc, const std::string res)
	{
		//if contains result of the function already - change result
		//else create(insert) new result of the function
		if (outInfo.count(nameFunc) == 1)
		{
			outInfo.find(nameFunc)->second = res;
		}
		else
		{
			outInfo.insert(std::pair<std::string, std::string>(nameFunc, res));
		}
	}

	const std::string TextEngine::getCommandOutput(const std::string nameFunc) const
	{
		return outInfo.find(nameFunc)->second;
	}

	bool TextEngine::isExistedFunc(const std::string & nameFunc)
	{
		auto func = fs.find(nameFunc);

		return (func != fs.end());
	}

	const funcs TextEngine::getRegisteredFuncs() const
	{
		return fs;
	}

	void TextEngine::call(anyFun f) const
	{
		f();
	}
}
