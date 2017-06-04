#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>

namespace my_exceptions
{
	class invalid : public std::exception{};
	class fail : public std::exception{};
}

#define VALIDATE_TEAM(team_id, n) (((team_id)<=0) || ((team_id)>(n)) == 0)

#endif // EXCEPTIONS_H_INCLUDED
