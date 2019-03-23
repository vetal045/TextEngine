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
		fs_ = te.getRegisteredFuncs();
	}

	TextEngine::TextEngine(TextEngine && te) : fs_(te.fs_)
	{
	}

	TextEngine & TextEngine::operator=(const TextEngine & other)
	{
		if (&other == this)
		{
			return *this;
		}

		this->fs_ = other.fs_;

		return *this;
	}

	TextEngine & TextEngine::operator=(TextEngine && other)
	{
		std::swap(*this, std::move(other));

		return *this;
	}

	void TextEngine::registerFunc(const std::string & nameFunc, anyFun funs)
	{
		auto funcToRegister = fs_.find(nameFunc);

		if (funcToRegister != fs_.end())
		{
			throw std::runtime_error("function is already registered.");
		}

		fs_.insert(std::pair<std::string, anyFun>(nameFunc, funs));
	}

	void TextEngine::deleteFunc(const std::string & nameFunc)
	{
		auto funcToDelete = getFunctionIterator(nameFunc);

		fs_.erase(funcToDelete);
	}

	void TextEngine::execFunc(const std::string & nameFunc)
	{
		auto funcToRun = getFunctionIterator(nameFunc);

		auto result = funcToRun->second(args_);

		setCommandOutput(nameFunc, result);
	}

	void TextEngine::execFunc(const std::string & nameFunc, const std::vector<std::string>& args)
	{
		auto funcToRun = getFunctionIterator(nameFunc);

		auto function = std::bind(funcToRun->second, args);

		std::string result = function();

		setCommandOutput(nameFunc, result);
	}

	void TextEngine::setCommandOutput(const std::string& nameFunc, const std::string& res)
	{
		auto funcToChange = outInfo_.find(nameFunc);

		//if contains result of the function already - change result
		//else create(insert) new result of the function
		if (funcToChange != outInfo_.end())
		{
			funcToChange->second = res;
		}
		else
		{
			outInfo_.insert(std::pair<std::string, std::string>(nameFunc, res));
		}
	}

	std::string TextEngine::getCommandOutput(const std::string& nameFunc) const
	{
		auto funcToReturn = outInfo_.find(nameFunc);

		if (funcToReturn != outInfo_.end())
		{
			return funcToReturn->second;
		}
		else
		{
			throw std::runtime_error("function is not existed.");
		}
	}

	bool TextEngine::isExistedFunc(const std::string & nameFunc)
	{
		auto func = fs_.find(nameFunc);

		return (func != fs_.end());
	}

	const funcs TextEngine::getRegisteredFuncs() const
	{
		return fs_;
	}

	funcs::const_iterator TextEngine::getFunctionIterator(const std::string & nameFunc) const
	{
		auto function = fs_.find(nameFunc);

		if (function != fs_.end())
		{
			return function;
		}
		else
		{
			throw std::runtime_error("function is not existed.");
		}
	}
}
