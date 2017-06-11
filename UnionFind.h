#ifndef UF_H_INCLUDED
#define UF_H_INCLUDED

#include "Exceptions.h"

using namespace my_exceptions;

class UnionFind
{
private:

    int uf_size;
    int* sets;
    int* sizes;
    int* wins;

public:

    UnionFind(int N);

    ~UnionFind();

    int size();

    int size(int ID);

    bool isInSet(int id);

    int Find(int id);

    void Union(int id1, int id2);

    bool areConnected(int id1, int id2);

    int get_wins(int id);

    void update_wins(int id);

};

#endif // UF_H_INCLUDED
