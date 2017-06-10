#include <iostream>
#include "Xmen.h"

typedef enum {
	EXISTS,
	DOESNT_EXIST
} Condition;

Student* Validate_Student(HashTable<Student>* ht, int Magi_ID, Condition cond);

Xmen::Xmen(int number_of_teams) :  teams(new UnionFind(int number_of_teams)),
                                   avl_students(new avl_rank[number_of_teams]), ht_students(new HashTable<Student>())
{
    for(int i=0; i<number_of_teams; i++)
        avl_students[i] = new avl_rank();
}

Xmen::Xmen(int numberOfTeams){
	teams = new UnionFind*(numberOfTeams);
	ht_students = new HashTable<Student*>;
	avl_students = new avl_rank<Student*>[numberOfTeams];

}

Xmen::~Xmen()
{
    for(int i=0; i<teams->size()(); i++)
        delete avl_students[i];
    delete teams;
    delete[] avl_students;
    delete ht_students;
}

void Xmen::AddStudent(int StudentID, int Team, int Power)
{
    if(Power <= Student_Defines::MIN_POWER) throw invalid();
    int x = teams->Find(Team);
    Validate_Student(ht_students, StudentID, DOESNT_EXIST);
    Student student(Power, x, StudentID);
    avl_students[x]->insert(StudentID, Power);
    ht_students->insert(StudentID, &student);
    //check if bigger than maxID power then we need to switch them and update the maxID;
}

void Xmen::RemoveStudent(int StudentID)
{
    Student* student = Validate_Student(ht_students, StudentID, EXISTS);
    int x = teams->Find(student->team());
    avl_students[x]->remove(StudentID, student->pwr());
    ht_students->remove(StudentID);
    if(StudentID == teams->maxID[x]{
    	//replace student with the most powerfull student in the team
    }
}

void Xmen::JoinTeams(int Team1, int Team2) //should we update the team variable in each student in the ht?
{
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    if(x==y) return;
    teams->Union(x, y);
    // Merge trees of x and y
}

void Xmen::TeamFight(int Team1, int Team2, int NumOfFighters)
{
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    int wins1 = teams->get_wins(x);
    int id = avl_students->find_newest_suitable(lvl);
    if(id == Avl_Defines::INVALID_ID) throw fail();
    Student* magi = ht_students->find(id);
    magi->addCreature(Creature);
    avl_students->remove(magi->ID, magi->level(), magi->seniority());
}

void Xmen::GetNumOfWins(int Team,int *Wins){
	if(Team <= 0 || Team >this->teams->size()){
		throw INVALID_INPUT;
	}
	int x=teams->Find(Team);
	Wins=teams->wins[x];
}

void Xmen::GetStudentTeamLeader(int StudentID,int *Leader){
	if(StudentID <=0) throw INVALID_INPUT; ////need to change to valite functon - not sure how it works
	Student * student=ht_students->find(StudentID);
	Leader=teams->maxID[student->team_ID];
}


Student* Validate_Student(HashTable<Student>* ht, int StudentID, Condition cond)
{
    if(StudentID <= Student_Defines::MIN_ID) throw invalid();
    Student* student = ht->find(StudentID);
    switch(cond)
    {
    case EXISTS :
        if(!student) throw fail();
        return student;

    case DOESNT_EXIST :
        if(student) throw fail();
        return NULL;
    }
    return NULL;
}
