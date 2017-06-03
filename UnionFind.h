#ifndef UF_H_INCLUDED
#define UF_H_INCLUDED

#include "Exceptions.h"

using namespace my_exceptions;

class UnionFind
{
private:

    int uf_size;
    int* levels;
    int* sets;
    int* sizes;

public:

    UnionFind(int N, int* levels);

    ~UnionFind();

    int size();

    bool isInSet(int id);

    int Find(int id);

    void Union(int id1, int id2);

    bool areConnected(int id1, int id2);

    int AreaSize(int id);

    int AreaLevel(int id);

};

#endif // UF_H_INCLUDED
