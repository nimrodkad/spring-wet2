#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Exceptions.h"

namespace Student_Defines
{
    const int MIN_ID = 0;
    const int MIN_POWER = 0;
    const int INVALID_ID = -1;
}

using namespace my_exceptions;

class Student
{
private:
    const int power;
    int team_ID;

public:
    const int ID;
    Student(int power, int team_ID, int id) : power(power), team_ID(team_ID), ID(id)
    {
        if(id <= Student_Defines::MIN_ID || power <= Student_Defines::MIN_POWER)
        {
            throw invalid();
        }
    }

    ~Student() {}

    int pwr()
    {
        return power;
    }

    int team()
    {
        return team_ID;
    }

};

#endif // STUDENT_H_INCLUDED
