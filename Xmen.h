#ifndef MAGICAL_CREATURES_H_INCLUDED
#define MAGICAL_CREATURES_H_INCLUDED

#include "avl_rank.h"
#include "UnionFind.h"
#include "hashTable.h"
#include "Magi.h"
#include "Exceptions.h"

using namespace my_exceptions;

class Magical_Creatures
{
private:

    static int Seniority;

    UnionFind* creatures;

    avl_rank* avl_magis;

    HashTable<Magi>* ht_magis;

public:

    Magical_Creatures(int number_of_creatures, int* levels);

    ~Magical_Creatures();

    void AddMagizoologist(int Magi_ID, int Magi_Level);

    void RemoveMagizoologist(int Magi_ID);

    void RemoveBarrier(int Creature1, int Creature2);

    void AssignMagizoologistToCreature(int Creature);

    void ReleaseMagizoologist(int Magi_ID);

    void GetCreatureOfMagi(int Magi_ID, int* Creature);

    void AreCreaturesInSameArea(int Creature1, int Creature2, bool* SameArea);

    void GetSizeOfArea(int Creature, int* SizeOfArea);

};

#endif // MAGICAL_CREATURES_H_INCLUDED
