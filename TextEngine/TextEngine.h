#pragma once

#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace TextEngine
{
	//aliases
	using anyFun = std::function<std::string(std::vector<std::string>)>;
	using funcs = std::map<std::string, anyFun>;

	//
	// Declaration of the class TextEngine.
	//

	class TextEngine
	{
		//
		// Construction and destruction.
		//

	public:
		TextEngine();
		TextEngine(const TextEngine& te);
		TextEngine(TextEngine&& te);

		//
		// Operators.
		//

		TextEngine& operator=(const TextEngine& other);
		TextEngine& operator=(TextEngine&& other);

		//
		// Private data members.
		//

	private:
		funcs fs_;
		std::map<std::string, std::string> outInfo_;
		std::vector<std::string> args_;

		//
		// Public methods.
		//

	public:
		void registerFunc(const std::string& nameFunc, anyFun funs);

		void deleteFunc(const std::string& nameFunc);

		void execFunc(const std::string& nameFunc);

		void execFunc(const std::string& nameFunc, const std::vector<std::string>& args);

		void setCommandOutput(const std::string& nameFunc,  const std::string& res);

		std::string getCommandOutput(const std::string& nameFunc) const;

		bool isExistedFunc(const std::string& nameFunc);

		const funcs getRegisteredFuncs() const;

		//
		// Private methods.
		//

	private:
		funcs::const_iterator getFunctionIterator(const std::string& nameFunc) const;
	};

	//it calls any funtion
	void call(anyFun f);
}