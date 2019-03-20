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

	//
	//helpfull functions
	//

	//! Gets command from entered line be user 
	const std::string getCommand(std::vector<std::string>& args_);

	//
	// Private data members.
	//

private:
	TextEngine::TextEngine te;
	std::vector<std::string> args;

	std::string command;
	//std::map<std::string, std::vector<std::string>> args;
};
