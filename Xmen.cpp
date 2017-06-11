#include <iostream>
#include "Xmen.h"

typedef enum {
	EXISTS,
	DOESNT_EXIST
} Condition;

Student* Validate_Student(HashTable<Student>* ht, int studentID, Condition cond);


Xmen::Xmen(int numberOfTeams){
	teams = new UnionFind(numberOfTeams);
	ht_students = new HashTable<Student>;
	avl_students= new avl_rank*[numberOfTeams];
	for(int i=0; i<numberOfTeams; i++){
		avl_students[i] = new avl_rank();
	}
}

Xmen::~Xmen()
{
    for(int i=0; i<teams->size(); i++){
        delete avl_students[i];
    }
    delete[] avl_students;
    delete ht_students;
    delete teams;
}

void Xmen::AddStudent(int StudentID, int Team, int Power)
{
	if(Power <= Student_Defines::MIN_POWER) throw invalid();
    Validate_Student(ht_students, StudentID, DOESNT_EXIST);
    int x = teams->Find(Team);
    Student student(Power, x, StudentID);
    avl_students[x]->insert(StudentID, Power);
    ht_students->insert(StudentID, &student);
}

void Xmen::RemoveStudent(int StudentID)
{
    Student* student = Validate_Student(ht_students, StudentID, EXISTS);
    int x = teams->Find(student->team());
    avl_students[x]->remove(StudentID, student->pwr());
    ht_students->remove(StudentID);
}

void Xmen::JoinTeams(int Team1, int Team2)
{
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    if(x==y) return;
    if(teams->size(x) < teams->size(y)){
    	avl_students[y]+=avl_students[x];
    }else{
    	avl_students[x]+=avl_students[y];
    }
    teams->Union(x, y);
}

void Xmen::TeamFight(int Team1, int Team2, int NumOfFighters)
{
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    if( x == y ) return; //same teams
//    int sum1=sumOfPower(avl_students[x],NumOfFighters);			////////////////////////////////////////////////				//TODO
//    int sum2=sumOfPower(avl_students[y],NumOfFighters);
//    if(sum1 > sum2){
//    	teams->update_wins(x);
//    }
//    else if(sum1 < sum2){
//    	teams->update_wins(y);
//    }
}

void Xmen::GetNumOfWins(int Team,int *Wins){
	*Wins=teams->get_wins(Team);
}

void Xmen::GetStudentTeamLeader(int StudentID,int *Leader){
    Student* student = Validate_Student(ht_students, StudentID, EXISTS);
	int x=teams->Find(student->team());
	*Leader=avl_students[x]->max_id; 										//TODO
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
