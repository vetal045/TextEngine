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

	TextEngine::TextEngine(TextEngine && te) : fs(te.fs)
	{
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

	TextEngine & TextEngine::operator=(TextEngine && other)
	{
		std::swap(*this, std::move(other));

		return *this;
	}

	void TextEngine::registerFunc(anyFun funs, const std::string & nameFunc)
	{
		auto funcToRegister = fs.find(nameFunc);

		if (funcToRegister != fs.end())
		{
			std::runtime_error("function is already registered.");
		}

		fs.insert(std::pair<std::string, anyFun>(nameFunc, funs));
	}

	void TextEngine::deleteFunc(const std::string & nameFunc)
	{
		auto funcToDelete = getFunctionIterator(nameFunc);

		fs.erase(funcToDelete);
	}

	void TextEngine::execFunc(const std::string & nameFunc)
	{
		auto funcToRun = getFunctionIterator(nameFunc);

		auto result = funcToRun->second();

		setCommandOutput(nameFunc, result);
	}

	void TextEngine::setCommandOutput(const std::string& nameFunc, const std::string& res)
	{
		auto funcToChange = outInfo.find(nameFunc);

		//if contains result of the function already - change result
		//else create(insert) new result of the function
		if (funcToChange != outInfo.end())
		{
			funcToChange->second = res;
		}
		else
		{
			outInfo.insert(std::pair<std::string, std::string>(nameFunc, res));
		}
	}

	std::string TextEngine::getCommandOutput(const std::string& nameFunc) const
	{
		auto funcToReturn = outInfo.find(nameFunc);

		if (funcToReturn != outInfo.end())
		{
			return funcToReturn->second;
		}
		else
		{
			std::runtime_error("function is not existed.");
		}
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

	funcs::const_iterator TextEngine::getFunctionIterator(const std::string & nameFunc) const
	{
		auto function = fs.find(nameFunc);

		if (function != fs.end())
		{
			return function;
		}
		else
		{
			std::runtime_error("function is not existed.");
		}
	}

	void call(anyFun f)
	{
		f();
	}
}
