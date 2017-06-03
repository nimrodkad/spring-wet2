#ifndef MAGICAL_CREATURES_H_INCLUDED
#define MAGICAL_CREATURES_H_INCLUDED

#include "avl_rank.h"
#include "UnionFind.h"
#include "hashTable.h"
#include "Student.h"
#include "Exceptions.h"

using namespace my_exceptions;

class Xmen
{
private:

    UnionFind* teams;

    avl_rank* avl_students;

    HashTable<Student>* ht_students;

public:

    Xmen(int number_of_teams);

    ~Xmen();

    void AddStudent(int StudentID, int Team ,int Power);

    void RemoveStudent(int StudentID);

    void JoinTeams(int Team1, int Team2);

    void TeamFight(int Team1, int Team2, int NumOfFighters);

    void GetNumOfWins(int Team, int* Wins);

    void GetStudentTeamLeader(int StudentID, int* Leader);

};

#endif // MAGICAL_CREATURES_H_INCLUDED
