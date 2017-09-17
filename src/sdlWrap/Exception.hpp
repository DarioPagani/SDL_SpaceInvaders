//
// Created by dario on 07/09/17.
//

#ifndef TESTSDL_EXCEPTION_HPP
#define TESTSDL_EXCEPTION_HPP

#include <system_error>

namespace sdl
{

/**
 * This class is for create an exception when something in SDL goes wrong
 * line and file args are suppost to be fill by the prepocessor macros __FILE__ and __LINE__
 * or by your self or do not use him anyway :P
 */
class Exception: public std::exception
{
public:
	Exception() = delete;
	Exception(const char * const msgErr, const int &line, const char * const file);
	Exception(const std::string &msgErr, const int &line, const char * const file);
	Exception(const char * const msgErr);
	Exception(const std::string &msgErr);

	const char* what() const throw();

private:
	std::string msgErr;
	std::string where;
	std::string complete;
};

}

#endif //TESTSDL_EXCEPTION_HPP
