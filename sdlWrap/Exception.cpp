//
// Created by dario on 07/09/17.
//

#include <iostream>
#include "Exception.hpp"

namespace sdl
{

Exception::Exception(const std::string &msgErr, const int &line, const char * const file)
{
	where = file ?: "NOFILE";
	where +=':';
	where += std::to_string(line);

	this->msgErr = (msgErr);

	complete = (where + "\t" + msgErr);
}

Exception::Exception(const char *const msgErr, const int &line, const char *const file)
{
	Exception(std::string(this->msgErr = msgErr ?: "NOERROR"), line, file);
}

Exception::Exception(const char *const msgErr)
{
	Exception(msgErr, 0, nullptr);
}

Exception::Exception(const std::string &msgErr)
{
	Exception(msgErr, 0, nullptr);
}

const char * Exception::what() const throw()
{
	//const char * const msgPtr = complete.c_str();
	return where.c_str();
}
}