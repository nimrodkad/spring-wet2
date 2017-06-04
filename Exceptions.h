#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>

namespace my_exceptions
{
	class invalid : public std::exception{};
	class fail : public std::exception{};
}

#endif // EXCEPTIONS_H_INCLUDED
