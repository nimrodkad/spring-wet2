#ifndef MAGI_H_INCLUDED
#define MAGI_H_INCLUDED

#include "Exceptions.h"

namespace Magi_Defines
{
    const int MIN_MAGI = 0;
    const int MIN_LEVEL = 0;
    const int INVALID_ID = -1;
}

using namespace my_exceptions;

class Magi
{
private:
    const int Magi_Level;
    const int Seniority;
    int Creature_ID;

public:
    const int ID;
    Magi(int MagiLevel, int Seniority, int id) : Magi_Level(MagiLevel), Seniority(Seniority), Creature_ID(Magi_Defines::INVALID_ID), ID(id)
    {
        if(id <= Magi_Defines::MIN_MAGI || MagiLevel <= Magi_Defines::MIN_LEVEL)
        {
            throw invalid();
        }
    }

    ~Magi() {}

    void addCreature(int creature_id)
    {
        if(isAssined()) throw fail();
        this->Creature_ID = creature_id;
    }

    void release()
    {
        if(!isAssined()) throw fail();
        this->Creature_ID = Magi_Defines::INVALID_ID;
    }

    int level()
    {
        return Magi_Level;
    }

    int seniority()
    {
        return Seniority;
    }

    bool isAssined()
    {
        return (Creature_ID != Magi_Defines::INVALID_ID);
    }

    int creatureAssined()
    {
        if(!isAssined()) throw fail();
        return Creature_ID;
    }

};

#endif // MAGI_H_INCLUDED
