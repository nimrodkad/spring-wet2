#include <iostream>
#include "Xmen.h"

typedef enum {
	EXISTS,
	DOESNT_EXIST
} Condition;

Student* Validate_Magi(HashTable<Student>* ht, int Magi_ID, Condition cond);

Xmen::Xmen(int number_of_creatures, int* levels) : creatures(new UnionFind(number_of_creatures, levels)),
                                                                                                                avl_magis(new avl_rank()),
                                                                                                                ht_magis(new HashTable<Student>()) {}

Xmen::~Xmen()
{
    delete creatures;
    delete avl_magis;
    delete ht_magis;
}

void Xmen::AddMagizoologist(int Magi_ID, int Magi_Level)
{
    if(Magi_Level <= Magi_Defines::MIN_LEVEL) throw invalid();
    Validate_Magi(ht_magis, Magi_ID, DOESNT_EXIST);
    Student magi(Magi_Level, Seniority, Magi_ID);
    avl_magis->insert(Magi_ID, Magi_Level, Seniority);
    ht_magis->insert(Magi_ID, &magi);
    Seniority++;
}

void Xmen::RemoveMagizoologist(int Magi_ID)
{
    Student* magi = Validate_Magi(ht_magis, Magi_ID, EXISTS);
    avl_magis->remove(Magi_ID, magi->level(), magi->seniority());
    ht_magis->remove(Magi_ID);
}

void Xmen::RemoveBarrier(int Creature1, int Creature2)
{
    creatures->Union(Creature1, Creature2);
}

void Xmen::AssignMagizoologistToCreature(int Creature)
{
    int x = creatures->Find(Creature);
    int lvl = creatures->AreaLevel(x);
    int id = avl_magis->find_newest_suitable(lvl);
    if(id == Avl_Defines::INVALID_ID) throw fail();
    Student* magi = ht_magis->find(id);
    magi->addCreature(Creature);
    avl_magis->remove(magi->ID, magi->level(), magi->seniority());
}

void Xmen::ReleaseMagizoologist(int Magi_ID)
{
    Student* magi = Validate_Magi(ht_magis, Magi_ID, EXISTS);
    magi->release();
    avl_magis->insert(Magi_ID, magi->level(), magi->seniority());
}

void Xmen::GetCreatureOfMagi(int Magi_ID, int* Creature)
{
    if(!Creature) throw invalid();
    Student* magi = Validate_Magi(ht_magis, Magi_ID, EXISTS);
    *Creature = magi->creatureAssined();
}

void Xmen::AreCreaturesInSameArea(int Creature1, int Creature2, bool* SameArea)
{
    if(!SameArea) throw invalid();
    *SameArea = creatures->areConnected(Creature1, Creature2);
}

void Xmen::GetSizeOfArea(int Creature, int* SizeOfArea)
{
    if(!SizeOfArea) throw invalid();
    int x = creatures->Find(Creature);
    *SizeOfArea = creatures->AreaSize(x);
}

Student* Validate_Magi(HashTable<Student>* ht, int Magi_ID, Condition cond)
{
    if(Magi_ID <= Magi_Defines::MIN_MAGI) throw invalid();
    Student* magi = ht->find(Magi_ID);
    switch(cond)
    {
    case EXISTS :
        if(!magi) throw fail();
        return magi;

    case DOESNT_EXIST :
        if(magi) throw fail();
        return NULL;
    }
    return NULL;
}
