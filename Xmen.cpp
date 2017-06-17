#include <iostream>
#include "Xmen.h"

typedef enum {
	EXISTS,
	DOESNT_EXIST
} Condition;

Student* Validate_Student(HashTable<Student>* ht, int studentID, Condition cond);
int sumOfPower(avl_rank *tree,int num);


Xmen::Xmen(int numberOfTeams)
{
	teams = new UnionFind(numberOfTeams);
	ht_students = new HashTable<Student>;
	avl_students= new avl_rank*[numberOfTeams + 1];
	for(int i=0; i<numberOfTeams + 1; i++){
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
    avl_students[x]->insert(StudentID, Power); //check if maxID changed
    ht_students->insert(StudentID, &student);
}

void Xmen::RemoveStudent(int StudentID)
{
    Student* student = Validate_Student(ht_students, StudentID, EXISTS);
    int x = teams->Find(student->team());
    avl_students[x]->remove(StudentID, student->pwr());
    ht_students->remove(StudentID);
}

void Xmen::JoinTeams(int Team1, int Team2) //should we also update the team variable in each student in the ht?
{//check for teams errors
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    if(x==y) return;
    //check x and y sizes before union for merging
    if(teams->size(x) < teams->size(y)){
    	*avl_students[y] += avl_students[x];
    }else{
    	*avl_students[x] += avl_students[y];
    }
    teams->Union(x, y);
}

void Xmen::TeamFight(int Team1, int Team2, int NumOfFighters)
{
    if(NumOfFighters <= 0) throw invalid();
    int x = teams->Find(Team1);
    int y = teams->Find(Team2);
    if( x == y ) return; //same teams
    int sum1=sumOfPower(avl_students[x],NumOfFighters);
    int sum2=sumOfPower(avl_students[y],NumOfFighters);
    if(sum1 > sum2){
    	teams->update_wins(x);
    }
    else if(sum1 < sum2){
    	teams->update_wins(y);
    }
    std::cout<<"Team "<<Team1<<" has "<<sum1<<" and team "<<Team2<<" has "<<sum2 <<std::endl;
}

void Xmen::GetNumOfWins(int Team,int *Wins)
{
    if(Team == 13)
    {
        avl_students[teams->Find(Team)]->print();
        std::cout<<std::endl;
    }
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

int sumOfPower(avl_rank* tree,int num)
{
	int treeSize=tree->get_size();
	if(!treeSize) return 0;
	if(num >= treeSize) return tree->get_root()->info.rank;
	avl_rank::Node* node=tree->select(treeSize-num+1);
	avl_rank::Node* last=tree->select(treeSize);
	int commonAncestor=tree->lowestCommonAncestor(node,last);
	if(node->left) return (commonAncestor - (node->left->info.rank));
	return commonAncestor;
}
