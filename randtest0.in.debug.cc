#include "library2.h"

void test() {
   int leader;
   int number_of_wins;
   void* DS = Init(14);
   GetNumOfWins(DS,1,&number_of_wins);
   AddStudent(DS,-1,2,63);
   JoinTeams(DS,11,7);
   GetNumOfWins(DS,2,&number_of_wins);
   GetStudentTeamLeader(DS,24,&leader);
   JoinTeams(DS,10,9);
   GetNumOfWins(DS,9,&number_of_wins);
   AddStudent(DS,11,6,31);
   JoinTeams(DS,3,13); // 10
   RemoveStudent(DS,23);
   TeamFight(DS,8,1,3);
   GetNumOfWins(DS,12,&number_of_wins);
   RemoveStudent(DS,7);
   GetStudentTeamLeader(DS,8,&leader);
   TeamFight(DS,11,4,1);
   TeamFight(DS,10,4,1);
   GetStudentTeamLeader(DS,42,&leader);
   GetNumOfWins(DS,4,&number_of_wins);
   AddStudent(DS,55,14,88); // 20
   AddStudent(DS,38,11,6);
   GetNumOfWins(DS,5,&number_of_wins);
   TeamFight(DS,9,14,-1);
   GetNumOfWins(DS,7,&number_of_wins);
   TeamFight(DS,10,6,-1);
   TeamFight(DS,14,10,3);
   GetStudentTeamLeader(DS,14,&leader);
   TeamFight(DS,5,12,2);
   TeamFight(DS,14,1,-1);
   TeamFight(DS,2,5,-1); // 30
   AddStudent(DS,35,3,12);
   AddStudent(DS,-1,12,97);
   GetStudentTeamLeader(DS,34,&leader);
   GetNumOfWins(DS,5,&number_of_wins);
   RemoveStudent(DS,0);
   TeamFight(DS,11,4,3);
   TeamFight(DS,3,7,-1);
   GetNumOfWins(DS,12,&number_of_wins);
   GetStudentTeamLeader(DS,5,&leader);
   GetStudentTeamLeader(DS,-1,&leader); // 40
   GetNumOfWins(DS,10,&number_of_wins);
   AddStudent(DS,50,5,86);
   AddStudent(DS,39,6,82);
   JoinTeams(DS,8,6);
   GetStudentTeamLeader(DS,35,&leader);
   GetNumOfWins(DS,11,&number_of_wins);
   AddStudent(DS,17,5,63);
   TeamFight(DS,12,3,1);
   JoinTeams(DS,10,6);
   AddStudent(DS,40,14,66); // 50
   TeamFight(DS,11,13,1);
   AddStudent(DS,55,4,50);
   TeamFight(DS,1,3,0);
   AddStudent(DS,10,5,74);
   TeamFight(DS,11,2,1);
   TeamFight(DS,3,12,2);
   JoinTeams(DS,8,14);
   AddStudent(DS,2,9,3);
   RemoveStudent(DS,23);
   TeamFight(DS,7,9,2); // 60
   RemoveStudent(DS,5);
   TeamFight(DS,14,3,2);
   TeamFight(DS,10,12,1);
   AddStudent(DS,18,1,35);
   GetStudentTeamLeader(DS,40,&leader);
   AddStudent(DS,23,12,75);
   TeamFight(DS,8,13,0);
   RemoveStudent(DS,15);
   GetNumOfWins(DS,12,&number_of_wins);
   AddStudent(DS,52,3,103); // 70
   RemoveStudent(DS,46);
   TeamFight(DS,2,7,3);
   GetStudentTeamLeader(DS,46,&leader);
   GetNumOfWins(DS,4,&number_of_wins);
   GetNumOfWins(DS,2,&number_of_wins);
   JoinTeams(DS,11,2);
   GetNumOfWins(DS,10,&number_of_wins);
   GetNumOfWins(DS,4,&number_of_wins);
   GetStudentTeamLeader(DS,42,&leader);
   GetStudentTeamLeader(DS,6,&leader); // 80
   RemoveStudent(DS,44);
   TeamFight(DS,2,6,1);
   AddStudent(DS,55,11,14);
   AddStudent(DS,21,4,54);
   RemoveStudent(DS,8);
   GetNumOfWins(DS,6,&number_of_wins);
   GetNumOfWins(DS,2,&number_of_wins);
   JoinTeams(DS,8,10);
   TeamFight(DS,3,1,2);
   RemoveStudent(DS,29); // 90
   TeamFight(DS,7,9,9);
   RemoveStudent(DS,23);
   RemoveStudent(DS,0);
   AddStudent(DS,51,13,79);
   TeamFight(DS,11,6,8);
   TeamFight(DS,14,9,7);
   RemoveStudent(DS,21);
   JoinTeams(DS,13,6);
   AddStudent(DS,21,12,24);
   GetNumOfWins(DS,14,&number_of_wins); // 100
   RemoveStudent(DS,39);
   RemoveStudent(DS,38);
   GetStudentTeamLeader(DS,21,&leader);
   GetNumOfWins(DS,4,&number_of_wins);
   JoinTeams(DS,12,6);
   RemoveStudent(DS,3);
   AddStudent(DS,39,3,30);
   GetNumOfWins(DS,4,&number_of_wins);
   GetStudentTeamLeader(DS,14,&leader);
   RemoveStudent(DS,51); // 110
   AddStudent(DS,3,12,76);
   GetStudentTeamLeader(DS,55,&leader);
   GetStudentTeamLeader(DS,23,&leader);
   TeamFight(DS,13,4,2);
   GetStudentTeamLeader(DS,27,&leader);
   TeamFight(DS,10,4,3);
   TeamFight(DS,2,14,3);
   RemoveStudent(DS,9);
   TeamFight(DS,4,8,0);
   GetNumOfWins(DS,1,&number_of_wins); // 120
   RemoveStudent(DS,41);
   AddStudent(DS,12,11,96);
   AddStudent(DS,46,9,104);
   RemoveStudent(DS,43);
   TeamFight(DS,9,8,7);
   TeamFight(DS,6,14,6);
   GetNumOfWins(DS,6,&number_of_wins);
   JoinTeams(DS,14,14);
   RemoveStudent(DS,49);
   TeamFight(DS,8,2,6); // 130
   AddStudent(DS,6,5,79);
   GetStudentTeamLeader(DS,2,&leader);
   AddStudent(DS,3,6,100);
   AddStudent(DS,8,6,14);
   TeamFight(DS,13,1,9);
   RemoveStudent(DS,48);
   RemoveStudent(DS,37);
   TeamFight(DS,9,11,3);
   TeamFight(DS,7,8,2);
   GetStudentTeamLeader(DS,51,&leader); // 140
   TeamFight(DS,3,9,7);
   GetStudentTeamLeader(DS,41,&leader);
   GetStudentTeamLeader(DS,10,&leader);
   TeamFight(DS,5,10,-1);
   GetNumOfWins(DS,8,&number_of_wins);
   GetStudentTeamLeader(DS,36,&leader);
   GetNumOfWins(DS,2,&number_of_wins);
   AddStudent(DS,29,12,86);
   TeamFight(DS,3,11,7);
   AddStudent(DS,12,10,103); // 150
   TeamFight(DS,1,1,2);
   TeamFight(DS,7,10,2);
   RemoveStudent(DS,42);
   GetStudentTeamLeader(DS,42,&leader);
   RemoveStudent(DS,2);
   GetNumOfWins(DS,6,&number_of_wins);
   RemoveStudent(DS,3);
   GetNumOfWins(DS,4,&number_of_wins);
   GetStudentTeamLeader(DS,46,&leader);
   AddStudent(DS,49,5,76); // 160
   TeamFight(DS,1,6,4);
   TeamFight(DS,9,8,4);
   AddStudent(DS,48,11,48);
   TeamFight(DS,3,11,1);
   AddStudent(DS,32,3,41);
   JoinTeams(DS,4,14);
   AddStudent(DS,13,4,65);
   TeamFight(DS,12,14,0);
   GetNumOfWins(DS,12,&number_of_wins);
   GetNumOfWins(DS,3,&number_of_wins); // 170
   AddStudent(DS,35,5,47);
   TeamFight(DS,14,7,2);
   AddStudent(DS,42,3,38);
   AddStudent(DS,21,6,93);
   RemoveStudent(DS,6);
   GetStudentTeamLeader(DS,4,&leader);
   TeamFight(DS,5,14,6);
   TeamFight(DS,7,11,6);
   TeamFight(DS,1,2,6);
   TeamFight(DS,8,1,9); // 180
   TeamFight(DS,7,5,7);
   GetNumOfWins(DS,11,&number_of_wins);
   GetStudentTeamLeader(DS,3,&leader);
   RemoveStudent(DS,46);
   GetStudentTeamLeader(DS,15,&leader);
   GetNumOfWins(DS,14,&number_of_wins);
   AddStudent(DS,36,12,21);
   GetStudentTeamLeader(DS,28,&leader);
   JoinTeams(DS,4,6);
   AddStudent(DS,30,4,95); // 190
   GetNumOfWins(DS,4,&number_of_wins);
   RemoveStudent(DS,39);
   TeamFight(DS,13,10,6);
   GetNumOfWins(DS,2,&number_of_wins);
   RemoveStudent(DS,11);
   JoinTeams(DS,1,1);
   GetStudentTeamLeader(DS,30,&leader);
   GetNumOfWins(DS,7,&number_of_wins);
   RemoveStudent(DS,33);
   TeamFight(DS,6,10,-1); // 200
   AddStudent(DS,43,3,81);
   TeamFight(DS,8,13,5);
   RemoveStudent(DS,54);
   GetStudentTeamLeader(DS,12,&leader);
   RemoveStudent(DS,32);
   TeamFight(DS,12,4,0);
   TeamFight(DS,2,14,2);
   AddStudent(DS,26,9,19);
   AddStudent(DS,44,5,78);
   GetNumOfWins(DS,5,&number_of_wins); // 210
   AddStudent(DS,11,6,78);
   TeamFight(DS,2,3,4);
   AddStudent(DS,28,3,88);
   TeamFight(DS,13,5,8);
   GetStudentTeamLeader(DS,3,&leader);
   TeamFight(DS,1,5,6);
   TeamFight(DS,14,1,9);
   GetStudentTeamLeader(DS,0,&leader);
   TeamFight(DS,13,7,5);
   RemoveStudent(DS,19); // 220
   TeamFight(DS,14,9,3);
   TeamFight(DS,3,12,7);
   AddStudent(DS,50,1,62);
   RemoveStudent(DS,37);
   TeamFight(DS,6,5,6);
   AddStudent(DS,50,12,51);
   JoinTeams(DS,11,11);
   TeamFight(DS,13,9,8);
   RemoveStudent(DS,24);
   AddStudent(DS,15,13,9); // 230
   AddStudent(DS,55,13,80);
   AddStudent(DS,19,7,51);
   GetStudentTeamLeader(DS,-1,&leader);
   TeamFight(DS,7,7,8);
   TeamFight(DS,3,3,0);
   RemoveStudent(DS,2);
   TeamFight(DS,14,9,4);
   GetStudentTeamLeader(DS,12,&leader);
   TeamFight(DS,8,10,-1);
   AddStudent(DS,13,10,48); // 240
   GetStudentTeamLeader(DS,20,&leader);
   GetNumOfWins(DS,5,&number_of_wins);
   AddStudent(DS,48,13,91);
   TeamFight(DS,6,1,5);
   GetNumOfWins(DS,13,&number_of_wins);
   AddStudent(DS,38,10,100);
   AddStudent(DS,23,11,40);
   AddStudent(DS,55,9,90);
   AddStudent(DS,9,5,103);
   RemoveStudent(DS,53);
   AddStudent(DS,25,14,99); // 250
   TeamFight(DS,13,3,-1);
   Quit(&DS);
}

int main()
{
    test();
    return 0;
}
