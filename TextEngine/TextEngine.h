#pragma once

#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace TextEngine
{
	//aliases
	using anyFun = std::function<void(void)>;
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

		//
		// Operators.
		//

		TextEngine& operator=(const TextEngine& other);

		//
		// Private data members.
		//

	private:
		funcs fs;
		std::vector<std::string> args;

		//
		// Public methods.
		//

	public:
		void registerFunc(anyFun funs, const std::string& nameFunc);

		//test
		//***
		//void registerFunc(const std::string& nameFunc, const std::vector<std::string>& args_);
		//***

		void execFunc(const std::string& nameFunc);

		//test too
		//***
		//void execFunc(const std::string& nameFunc, const std::vector<std::string>& args_);
		//***

		bool isExistedFunc(const std::string& nameFunc);
		const funcs getRegisteredFuncs() const;

		//
		// Private methods.
		//
	private:
		
	};
}