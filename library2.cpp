#include "library2.h"
#include "Xmen.h"

void* Init(int n)
{
    Xmen* DS = new Xmen(n);
    return (void*)DS;
}

void assert_not_null(void* DS)
{
    if(!DS) throw my_exceptions::invalid();
}

StatusType AddStudent(void *DS, int StudentID, int Team ,int Power)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->AddStudent(StudentID, Team, Power);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType RemoveStudent(void *DS, int StudentID)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->RemoveStudent(StudentID);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType JoinTeams(void *DS, int Team1, int Team2)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->JoinTeams(Team1, Team2);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType TeamFight(void *DS, int Team1, int Team2, int NumOfFighters)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->TeamFight(Team1, Team2, NumOfFighters);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetNumOfWins(void *DS, int Team, int* Wins)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->GetNumOfWins(Team, Wins);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

StatusType GetStudentTeamLeader(void *DS, int StudentID, int* Leader)
{
    try
    {
        assert_not_null(DS);
        ((Xmen*)DS)->GetStudentTeamLeader(StudentID, Leader);
    }
    catch(std::bad_alloc e)
    {
        return ALLOCATION_ERROR;
    }
    catch(my_exceptions::invalid e)
    {
        return INVALID_INPUT;
    }
    catch(my_exceptions::fail e)
    {
        return FAILURE;
    }
    return SUCCESS;
}

void Quit(void** DS)
{
    try
    {
        assert_not_null(DS);
        assert_not_null(*DS);
    }
    catch(my_exceptions::invalid)
    {
        return;
    }
    delete *(Xmen**)DS;
    *DS = NULL;
    return;
}
