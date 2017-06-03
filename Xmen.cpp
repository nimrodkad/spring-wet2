#include <iostream>
#include "Xmen.h"

typedef enum {
	EXISTS,
	DOESNT_EXIST
} Condition;

Student* Validate_Student(HashTable<Student>* ht, int Magi_ID, Condition cond);

Xmen::Xmen(int number_of_teams) :  teams(new UnionFind(int number_of_teams)),
                                   avl_students(new avl_rank()), ht_students(new HashTable<Student>()){}

Xmen::~Xmen()
{
    delete teams;
    delete avl_students;
    delete ht_students;
}

void AddStudent(int StudentID, int Team ,int Power)
{
    if(Power <= Student_Defines::MIN_POWER) throw invalid();
    Validate_Student(ht_students, Magi_ID, DOESNT_EXIST);
    Student magi(Magi_Level, Seniority, Magi_ID);
    avl_students->insert(Magi_ID, Magi_Level, Seniority);
    ht_students->insert(Magi_ID, &magi);
    Seniority++;
}

void Xmen::RemoveMagizoologist(int Magi_ID)
{
    Student* magi = Validate_Student(ht_students, Magi_ID, EXISTS);
    avl_students->remove(Magi_ID, magi->level(), magi->seniority());
    ht_students->remove(Magi_ID);
}

void Xmen::RemoveBarrier(int Creature1, int Creature2)
{
    teams->Union(Creature1, Creature2);
}

void Xmen::AssignMagizoologistToCreature(int Creature)
{
    int x = teams->Find(Creature);
    int lvl = teams->AreaLevel(x);
    int id = avl_students->find_newest_suitable(lvl);
    if(id == Avl_Defines::INVALID_ID) throw fail();
    Student* magi = ht_students->find(id);
    magi->addCreature(Creature);
    avl_students->remove(magi->ID, magi->level(), magi->seniority());
}

void Xmen::ReleaseMagizoologist(int Magi_ID)
{
    Student* magi = Validate_Student(ht_students, Magi_ID, EXISTS);
    magi->release();
    avl_students->insert(Magi_ID, magi->level(), magi->seniority());
}

void Xmen::GetCreatureOfMagi(int Magi_ID, int* Creature)
{
    if(!Creature) throw invalid();
    Student* magi = Validate_Student(ht_students, Magi_ID, EXISTS);
    *Creature = magi->creatureAssined();
}

Student* Validate_Student(HashTable<Student>* ht, int Magi_ID, Condition cond)
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
