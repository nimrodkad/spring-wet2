#include "library2.h"

void test() {
   int leader;
   int number_of_wins;
   void* DS = Init(16);
   AddStudent(DS,42,9,49);
   AddStudent(DS,6,7,119);
   RemoveStudent(DS,8);
   RemoveStudent(DS,20);
   GetNumOfWins(DS,8,&number_of_wins);
   AddStudent(DS,23,5,110);
   TeamFight(DS,11,16,1);
   TeamFight(DS,1,14,1);
   RemoveStudent(DS,7); // 10
   TeamFight(DS,12,13,4);
   GetStudentTeamLeader(DS,31,&leader);
   AddStudent(DS,47,14,116);
   RemoveStudent(DS,28);
   AddStudent(DS,52,15,128);
   GetNumOfWins(DS,7,&number_of_wins);
   TeamFight(DS,14,13,3);
   AddStudent(DS,15,7,53);
   GetNumOfWins(DS,2,&number_of_wins);
   AddStudent(DS,26,13,37); // 20
   GetNumOfWins(DS,1,&number_of_wins);
   GetNumOfWins(DS,6,&number_of_wins);
   RemoveStudent(DS,61);
   RemoveStudent(DS,57);
   AddStudent(DS,19,6,10);
   AddStudent(DS,59,8,116);
   GetStudentTeamLeader(DS,28,&leader);
   AddStudent(DS,42,15,20);
   TeamFight(DS,12,6,4);
   GetStudentTeamLeader(DS,22,&leader); // 30
   GetStudentTeamLeader(DS,38,&leader);
   TeamFight(DS,3,7,4);
   TeamFight(DS,13,8,4);
   RemoveStudent(DS,8);
   JoinTeams(DS,15,1);
   GetStudentTeamLeader(DS,44,&leader);
   AddStudent(DS,1,7,43);
   RemoveStudent(DS,42);
   GetNumOfWins(DS,1,&number_of_wins);
   AddStudent(DS,-1,6,133); // 40
   TeamFight(DS,16,13,1);
   GetNumOfWins(DS,11,&number_of_wins);
   TeamFight(DS,8,13,4);
   GetStudentTeamLeader(DS,38,&leader);
   RemoveStudent(DS,2);
   RemoveStudent(DS,29);
   AddStudent(DS,45,16,24);
   GetNumOfWins(DS,1,&number_of_wins);
   GetNumOfWins(DS,8,&number_of_wins);
   AddStudent(DS,19,4,32); // 50
   GetStudentTeamLeader(DS,43,&leader);
   RemoveStudent(DS,1);
   RemoveStudent(DS,3);
   GetStudentTeamLeader(DS,58,&leader);
   AddStudent(DS,3,12,45);
   TeamFight(DS,3,4,1);
   TeamFight(DS,15,2,2);
   GetNumOfWins(DS,11,&number_of_wins);
   AddStudent(DS,53,1,88);
   AddStudent(DS,40,2,86); // 60
   AddStudent(DS,58,5,72);
   JoinTeams(DS,3,4);
   TeamFight(DS,15,5,-1);
   RemoveStudent(DS,46);
   GetStudentTeamLeader(DS,54,&leader);
   GetNumOfWins(DS,7,&number_of_wins);
   RemoveStudent(DS,46);
   GetNumOfWins(DS,3,&number_of_wins);
   TeamFight(DS,15,3,2);
   GetNumOfWins(DS,1,&number_of_wins); // 70
   TeamFight(DS,5,12,2);
   GetNumOfWins(DS,3,&number_of_wins);
   GetNumOfWins(DS,1,&number_of_wins);
   GetNumOfWins(DS,14,&number_of_wins);
   TeamFight(DS,4,7,1);
   TeamFight(DS,4,12,0);
   TeamFight(DS,3,7,-1);
   GetNumOfWins(DS,10,&number_of_wins);
   AddStudent(DS,26,11,60);
   GetNumOfWins(DS,1,&number_of_wins); // 80
   GetNumOfWins(DS,11,&number_of_wins);
   RemoveStudent(DS,16);
   TeamFight(DS,13,2,-1);
   AddStudent(DS,44,3,66);
   AddStudent(DS,63,16,10);
   AddStudent(DS,56,7,55);
   GetStudentTeamLeader(DS,5,&leader);
   GetStudentTeamLeader(DS,61,&leader);
   AddStudent(DS,39,8,124);
   AddStudent(DS,4,14,33); // 90
   AddStudent(DS,44,14,94);
   RemoveStudent(DS,1);
   GetStudentTeamLeader(DS,57,&leader);
   GetStudentTeamLeader(DS,18,&leader);
   TeamFight(DS,6,2,9);
   GetStudentTeamLeader(DS,10,&leader);
   GetNumOfWins(DS,16,&number_of_wins);
   GetStudentTeamLeader(DS,31,&leader);
   TeamFight(DS,15,14,3);
   GetNumOfWins(DS,13,&number_of_wins); // 100
   AddStudent(DS,3,10,99);
   AddStudent(DS,36,7,106);
   RemoveStudent(DS,48);
   GetStudentTeamLeader(DS,36,&leader);
   GetStudentTeamLeader(DS,54,&leader);
   GetNumOfWins(DS,8,&number_of_wins);
   AddStudent(DS,31,15,25);
   AddStudent(DS,57,5,115);
   GetNumOfWins(DS,2,&number_of_wins);
   TeamFight(DS,13,1,3); // 110
   AddStudent(DS,32,16,85);
   GetNumOfWins(DS,16,&number_of_wins);
   GetStudentTeamLeader(DS,5,&leader);
   GetNumOfWins(DS,14,&number_of_wins);
   GetNumOfWins(DS,11,&number_of_wins);
   JoinTeams(DS,10,3);
   GetNumOfWins(DS,12,&number_of_wins);
   GetStudentTeamLeader(DS,43,&leader);
   TeamFight(DS,4,7,-1);
   RemoveStudent(DS,44); // 120
   TeamFight(DS,12,9,-1);
   TeamFight(DS,13,11,8);
   GetStudentTeamLeader(DS,58,&leader);
   TeamFight(DS,12,6,7);
   GetStudentTeamLeader(DS,39,&leader);
   TeamFight(DS,11,5,2);
   RemoveStudent(DS,46);
   AddStudent(DS,26,11,37);
   AddStudent(DS,52,12,124);
   GetStudentTeamLeader(DS,39,&leader); // 130
   RemoveStudent(DS,39);
   AddStudent(DS,45,9,55);
   RemoveStudent(DS,47);
   JoinTeams(DS,3,13);
   JoinTeams(DS,2,4);
   GetNumOfWins(DS,11,&number_of_wins);
   GetStudentTeamLeader(DS,39,&leader);
   TeamFight(DS,8,16,4);
   AddStudent(DS,28,15,66);
   GetNumOfWins(DS,16,&number_of_wins); // 140
   TeamFight(DS,11,4,0);
   TeamFight(DS,5,3,3);
   GetNumOfWins(DS,14,&number_of_wins);
   AddStudent(DS,63,14,58);
   TeamFight(DS,10,4,5);
   RemoveStudent(DS,54);
   AddStudent(DS,25,2,113);
   GetStudentTeamLeader(DS,19,&leader);
   AddStudent(DS,32,9,71);
   GetNumOfWins(DS,11,&number_of_wins); // 150
   AddStudent(DS,15,15,84);
   AddStudent(DS,13,12,19);
   JoinTeams(DS,9,3);
   GetNumOfWins(DS,11,&number_of_wins);
   AddStudent(DS,34,12,9);
   RemoveStudent(DS,57);
   AddStudent(DS,60,2,75);
   AddStudent(DS,50,9,33);
   GetNumOfWins(DS,5,&number_of_wins);
   AddStudent(DS,24,15,7); // 160
   JoinTeams(DS,14,2);
   AddStudent(DS,54,11,50);
   AddStudent(DS,13,8,108);
   JoinTeams(DS,6,14);
   RemoveStudent(DS,52);
   TeamFight(DS,16,7,-1);
   AddStudent(DS,48,16,38);
   GetStudentTeamLeader(DS,6,&leader);
   GetStudentTeamLeader(DS,11,&leader);
   GetStudentTeamLeader(DS,8,&leader); // 170
   GetNumOfWins(DS,2,&number_of_wins);
   AddStudent(DS,39,6,4);
   RemoveStudent(DS,49);
   TeamFight(DS,14,11,5);
   GetNumOfWins(DS,3,&number_of_wins);
   AddStudent(DS,40,2,86);
   GetNumOfWins(DS,13,&number_of_wins);
   AddStudent(DS,12,13,74);
   GetStudentTeamLeader(DS,45,&leader);
   GetStudentTeamLeader(DS,54,&leader); // 180
   GetNumOfWins(DS,11,&number_of_wins);
   TeamFight(DS,13,4,2);
   AddStudent(DS,13,7,83);
   GetStudentTeamLeader(DS,45,&leader);
   TeamFight(DS,8,13,3);
   RemoveStudent(DS,58);
   TeamFight(DS,6,3,2);
   GetNumOfWins(DS,16,&number_of_wins);
   TeamFight(DS,7,13,4);
   AddStudent(DS,3,8,67); // 190
   GetNumOfWins(DS,8,&number_of_wins);
   AddStudent(DS,11,9,116);
   GetNumOfWins(DS,10,&number_of_wins);
   GetNumOfWins(DS,7,&number_of_wins);
   TeamFight(DS,3,2,7);
   RemoveStudent(DS,63);
   TeamFight(DS,13,10,1);
   RemoveStudent(DS,32);
   RemoveStudent(DS,34);
   GetNumOfWins(DS,7,&number_of_wins); // 200
   AddStudent(DS,42,14,95);
   RemoveStudent(DS,24);
   JoinTeams(DS,14,14);
   RemoveStudent(DS,49);
   RemoveStudent(DS,45);
   AddStudent(DS,-1,10,23);
   JoinTeams(DS,8,15);
   TeamFight(DS,1,9,6);
   JoinTeams(DS,15,15);
   JoinTeams(DS,15,4); // 210
   RemoveStudent(DS,30);
   AddStudent(DS,40,10,24);
   AddStudent(DS,48,10,76);
   AddStudent(DS,41,7,84);
   RemoveStudent(DS,59);
   RemoveStudent(DS,37);
   TeamFight(DS,11,4,4);
   AddStudent(DS,18,6,24);
   AddStudent(DS,37,13,72);
   TeamFight(DS,6,11,7); // 220
   TeamFight(DS,9,13,4);
   GetStudentTeamLeader(DS,27,&leader);
   RemoveStudent(DS,2);
   AddStudent(DS,3,14,2);
   TeamFight(DS,1,6,5);
   AddStudent(DS,59,12,123);
   JoinTeams(DS,7,1);
   AddStudent(DS,11,3,127);
   AddStudent(DS,1,6,121);
   GetStudentTeamLeader(DS,59,&leader); // 230
   AddStudent(DS,59,9,131);
   TeamFight(DS,15,5,1);
   AddStudent(DS,23,5,124);
   TeamFight(DS,8,10,-1);
   TeamFight(DS,3,2,9);
   TeamFight(DS,15,5,0);
   AddStudent(DS,39,10,0);
   TeamFight(DS,10,15,0);
   RemoveStudent(DS,4);
   TeamFight(DS,6,16,2); // 240
   GetNumOfWins(DS,5,&number_of_wins);
   RemoveStudent(DS,22);
   RemoveStudent(DS,51);
   AddStudent(DS,37,1,78);
   AddStudent(DS,49,9,117);
   GetStudentTeamLeader(DS,4,&leader);
   AddStudent(DS,48,14,85);
   GetNumOfWins(DS,10,&number_of_wins);
   TeamFight(DS,14,16,1);
   JoinTeams(DS,8,14); // 250
   TeamFight(DS,2,5,-1);
   GetStudentTeamLeader(DS,18,&leader);
   TeamFight(DS,2,9,2);
   RemoveStudent(DS,12);
   RemoveStudent(DS,35);
   AddStudent(DS,36,12,25);
   GetStudentTeamLeader(DS,55,&leader);
   GetNumOfWins(DS,13,&number_of_wins);
   GetNumOfWins(DS,10,&number_of_wins);
   GetStudentTeamLeader(DS,10,&leader); // 260
   AddStudent(DS,50,11,65);
   AddStudent(DS,61,10,-1);
   RemoveStudent(DS,15);
   RemoveStudent(DS,21);
   GetStudentTeamLeader(DS,34,&leader);
   TeamFight(DS,4,10,5);
   RemoveStudent(DS,21);
   AddStudent(DS,5,4,3);
   TeamFight(DS,11,1,3);
   TeamFight(DS,11,14,2); // 270
   GetStudentTeamLeader(DS,53,&leader);
   GetNumOfWins(DS,14,&number_of_wins);
   GetStudentTeamLeader(DS,28,&leader);
   RemoveStudent(DS,57);
   GetNumOfWins(DS,10,&number_of_wins);
   JoinTeams(DS,8,3);
   JoinTeams(DS,14,9);
   AddStudent(DS,13,7,39);
   TeamFight(DS,10,13,3);
   GetNumOfWins(DS,12,&number_of_wins); // 280
   AddStudent(DS,44,5,41);
   TeamFight(DS,11,3,2);
   TeamFight(DS,6,3,2);
   TeamFight(DS,10,1,3);
   TeamFight(DS,8,2,9);
   GetStudentTeamLeader(DS,62,&leader);
   TeamFight(DS,11,8,-1);
   AddStudent(DS,0,1,55);
   AddStudent(DS,62,8,11);
   RemoveStudent(DS,10); // 290
   GetNumOfWins(DS,9,&number_of_wins);
   GetStudentTeamLeader(DS,7,&leader);
   TeamFight(DS,11,4,3);
   GetStudentTeamLeader(DS,1,&leader);
   GetStudentTeamLeader(DS,52,&leader);
   GetStudentTeamLeader(DS,43,&leader);
   JoinTeams(DS,2,11);
   AddStudent(DS,45,9,88);
   GetNumOfWins(DS,7,&number_of_wins);
   JoinTeams(DS,2,1); // 300
   AddStudent(DS,21,12,134);
   TeamFight(DS,3,6,3);
   AddStudent(DS,38,5,45);
   GetStudentTeamLeader(DS,33,&leader);
   TeamFight(DS,9,14,7);
   AddStudent(DS,21,9,91);
   GetStudentTeamLeader(DS,57,&leader);
   GetNumOfWins(DS,3,&number_of_wins);
   AddStudent(DS,29,16,75);
   GetNumOfWins(DS,1,&number_of_wins); // 310
   AddStudent(DS,41,6,8);
   AddStudent(DS,43,10,0);
   TeamFight(DS,15,12,9);
   RemoveStudent(DS,32);
   GetNumOfWins(DS,6,&number_of_wins);
   TeamFight(DS,9,5,8);
   JoinTeams(DS,1,13);
   GetNumOfWins(DS,13,&number_of_wins);
   AddStudent(DS,8,7,60);
   AddStudent(DS,33,4,83); // 320
   TeamFight(DS,15,4,1);
   AddStudent(DS,50,14,18);
   GetStudentTeamLeader(DS,29,&leader);
   TeamFight(DS,2,9,0);
   GetStudentTeamLeader(DS,61,&leader);
   TeamFight(DS,3,12,0);
   RemoveStudent(DS,11);
   TeamFight(DS,8,3,6);
   AddStudent(DS,31,7,96);
   AddStudent(DS,26,8,36); // 330
   JoinTeams(DS,11,8);
   TeamFight(DS,7,5,6);
   JoinTeams(DS,13,15);
   AddStudent(DS,30,13,78);
   AddStudent(DS,40,16,120);
   AddStudent(DS,19,1,129);
   GetNumOfWins(DS,8,&number_of_wins);
   GetStudentTeamLeader(DS,56,&leader);
   GetStudentTeamLeader(DS,23,&leader);
   GetNumOfWins(DS,7,&number_of_wins); // 340
   RemoveStudent(DS,51);
   GetStudentTeamLeader(DS,39,&leader);
   JoinTeams(DS,8,4);
   GetStudentTeamLeader(DS,34,&leader);
   TeamFight(DS,2,11,-1);
   AddStudent(DS,61,7,94);
   JoinTeams(DS,16,5);
   AddStudent(DS,32,12,42);
   AddStudent(DS,59,13,102);
   TeamFight(DS,9,6,0); // 350
   AddStudent(DS,55,6,4);
   RemoveStudent(DS,7);
   GetNumOfWins(DS,13,&number_of_wins);
   RemoveStudent(DS,40);
   GetNumOfWins(DS,14,&number_of_wins);
   AddStudent(DS,10,5,18);
   TeamFight(DS,13,10,4);
   GetNumOfWins(DS,15,&number_of_wins);
   GetNumOfWins(DS,1,&number_of_wins);
   TeamFight(DS,4,12,2); // 360
   TeamFight(DS,6,6,5);
   GetStudentTeamLeader(DS,1,&leader);
   AddStudent(DS,36,4,82);
   AddStudent(DS,52,3,72);
   RemoveStudent(DS,23);
   RemoveStudent(DS,12);
   AddStudent(DS,27,6,130);
   GetNumOfWins(DS,13,&number_of_wins);
   AddStudent(DS,20,4,89);
   TeamFight(DS,1,10,13); // 370
   GetStudentTeamLeader(DS,42,&leader);
   JoinTeams(DS,12,1);
   RemoveStudent(DS,44);
   AddStudent(DS,36,13,56);
   AddStudent(DS,24,14,81);
   JoinTeams(DS,3,8);
   JoinTeams(DS,5,16);
   RemoveStudent(DS,49);
   JoinTeams(DS,14,4);
   TeamFight(DS,5,7,4); // 380
   GetStudentTeamLeader(DS,48,&leader);
   AddStudent(DS,57,3,38);
   TeamFight(DS,15,5,3);
   AddStudent(DS,54,2,132);
   AddStudent(DS,43,8,6);
   TeamFight(DS,16,1,13);
   GetNumOfWins(DS,13,&number_of_wins);
   AddStudent(DS,40,6,94);
   TeamFight(DS,15,4,4);
   TeamFight(DS,2,15,9); // 390
   AddStudent(DS,63,3,76);
   GetStudentTeamLeader(DS,48,&leader);
   GetStudentTeamLeader(DS,17,&leader);
   JoinTeams(DS,9,7);
   AddStudent(DS,40,8,110);
   AddStudent(DS,27,7,97);
   AddStudent(DS,19,15,12);
   AddStudent(DS,14,16,36);
   GetNumOfWins(DS,12,&number_of_wins);
   RemoveStudent(DS,27); // 400
   GetNumOfWins(DS,7,&number_of_wins);
   GetStudentTeamLeader(DS,50,&leader);
   TeamFight(DS,14,10,7);
   RemoveStudent(DS,33);
   AddStudent(DS,4,5,133);
   GetNumOfWins(DS,11,&number_of_wins);
   AddStudent(DS,46,13,62);
   GetStudentTeamLeader(DS,18,&leader);
   GetNumOfWins(DS,6,&number_of_wins);
   AddStudent(DS,62,9,130); // 410
   TeamFight(DS,16,11,0);
   RemoveStudent(DS,45);
   RemoveStudent(DS,59);
   TeamFight(DS,15,14,0);
   GetNumOfWins(DS,15,&number_of_wins);
   GetNumOfWins(DS,13,&number_of_wins);
   TeamFight(DS,8,7,11);
   TeamFight(DS,15,1,3);
   GetStudentTeamLeader(DS,58,&leader);
   GetStudentTeamLeader(DS,51,&leader); // 420
   GetStudentTeamLeader(DS,37,&leader);
   GetStudentTeamLeader(DS,61,&leader);
   TeamFight(DS,8,7,3);
   AddStudent(DS,50,14,64);
   AddStudent(DS,2,11,113);
   TeamFight(DS,2,14,8);
   TeamFight(DS,6,10,7);
   AddStudent(DS,47,7,44);
   AddStudent(DS,20,3,39);
   TeamFight(DS,6,2,1); // 430
   AddStudent(DS,60,4,20);
   RemoveStudent(DS,61);
   TeamFight(DS,8,11,10);
   GetNumOfWins(DS,9,&number_of_wins);
   RemoveStudent(DS,43);
   GetStudentTeamLeader(DS,14,&leader);
   GetStudentTeamLeader(DS,25,&leader);
   GetStudentTeamLeader(DS,48,&leader);
   TeamFight(DS,14,8,12);
   RemoveStudent(DS,35); // 440
   RemoveStudent(DS,23);
   TeamFight(DS,12,12,-1);
   TeamFight(DS,14,12,14);
   RemoveStudent(DS,19);
   TeamFight(DS,9,15,5);
   AddStudent(DS,56,3,0);
   AddStudent(DS,24,9,101);
   TeamFight(DS,4,4,7);
   AddStudent(DS,40,16,58);
   GetNumOfWins(DS,5,&number_of_wins); // 450
   TeamFight(DS,6,7,14);
   GetStudentTeamLeader(DS,43,&leader);
   AddStudent(DS,47,6,129);
   AddStudent(DS,10,9,1);
   GetStudentTeamLeader(DS,14,&leader);
   GetNumOfWins(DS,2,&number_of_wins);
   TeamFight(DS,5,10,9);
   AddStudent(DS,27,1,27);
   RemoveStudent(DS,34);
   TeamFight(DS,5,10,14); // 460
   RemoveStudent(DS,3);
   GetNumOfWins(DS,12,&number_of_wins);
   AddStudent(DS,20,15,98);
   TeamFight(DS,5,12,7);
   RemoveStudent(DS,34);
   RemoveStudent(DS,7);
   JoinTeams(DS,2,9);
   TeamFight(DS,9,11,13);
   RemoveStudent(DS,27);
   AddStudent(DS,20,7,70); // 470
   GetStudentTeamLeader(DS,34,&leader);
   AddStudent(DS,17,11,1);
   TeamFight(DS,5,1,1);
   GetNumOfWins(DS,4,&number_of_wins);
   GetStudentTeamLeader(DS,43,&leader);
   AddStudent(DS,27,14,57);
   AddStudent(DS,49,14,10);
   GetStudentTeamLeader(DS,45,&leader);
   GetStudentTeamLeader(DS,54,&leader);
   GetNumOfWins(DS,15,&number_of_wins); // 480
   GetNumOfWins(DS,13,&number_of_wins);
   RemoveStudent(DS,25);
   AddStudent(DS,31,15,23);
   RemoveStudent(DS,31);
   AddStudent(DS,20,16,44);
   GetNumOfWins(DS,14,&number_of_wins);
   GetStudentTeamLeader(DS,38,&leader);
   AddStudent(DS,48,16,32);
   AddStudent(DS,23,13,28);
   GetNumOfWins(DS,4,&number_of_wins); // 490
   AddStudent(DS,33,5,86);
   GetStudentTeamLeader(DS,61,&leader);
   AddStudent(DS,33,7,102);
   GetStudentTeamLeader(DS,30,&leader);
   RemoveStudent(DS,55);
   JoinTeams(DS,1,3);
   TeamFight(DS,4,4,8);
   TeamFight(DS,11,9,1);
   JoinTeams(DS,16,8);
   GetStudentTeamLeader(DS,56,&leader); // 500
   GetStudentTeamLeader(DS,19,&leader);
   Quit(&DS);
}

int main()
{
    test();
    return 0;
}
