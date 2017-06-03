#include "library2.h"
#include "Magical_Creatures.h"

void* Init(int n, int* levels)
{
    Magical_Creatures* DS = new Magical_Creatures(n, levels);
    return (void*)DS;
}

void assert_not_null(void* DS)
{
    if(!DS) throw my_exceptions::invalid();
}

StatusType AddMagizoologist(void *DS, int magiID, int magiLevel)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->AddMagizoologist(magiID, magiLevel);
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

StatusType RemoveMagizoologist(void *DS, int magiID)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->RemoveMagizoologist(magiID);
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

StatusType RemoveBarrier(void *DS, int creature1, int creature2)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->RemoveBarrier(creature1, creature2);
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

StatusType AssignMagizoologistToCreature(void *DS, int creatureID)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->AssignMagizoologistToCreature(creatureID);
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

StatusType ReleaseMagizoologist(void *DS, int magiID)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->ReleaseMagizoologist(magiID);
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

StatusType GetCreatureOfMagi(void *DS, int magiID, int* creatureID)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->GetCreatureOfMagi(magiID, creatureID);
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

StatusType AreCreaturesInSameArea(void *DS, int creature1, int creature2,  bool* sameArea)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->AreCreaturesInSameArea(creature1, creature2, sameArea);
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

StatusType GetSizeOfArea(void *DS, int creatureID, int* sizeOfArea)
{
    try
    {
        assert_not_null(DS);
        ((Magical_Creatures*)DS)->GetSizeOfArea(creatureID, sizeOfArea);
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
    delete *(Magical_Creatures**)DS;
    *DS = NULL;
    return;
}
