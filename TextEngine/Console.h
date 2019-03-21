#pragma once

#include "TextEngine.h"

#include <string>
#include <vector>
#include <map>

//
// Declaration of the class Console.
//

class Console
{
	//
	// Construction and destruction.
	//

public:
	Console();
	
	//
	// Public methods.
	//

public:
	void work();
	void addFunc(const std::string nameFunc, TextEngine::anyFun func);

	//
	//Helpfull functions
	//

	//! Gets command from entered line be user 
	const std::string getCommand(std::vector<std::string>& args_);

	//
	// Private data members.
	//

private:
	TextEngine::TextEngine te;
	std::vector<TextEngine::anyFun> registeredFuncs;
	std::vector<std::string> args;
};
