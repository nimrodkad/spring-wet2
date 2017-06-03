#include "UnionFind.h"

UnionFind::UnionFind(int N) : uf_size(N)
{
    if(N <= 0) throw fail();
    this->sets = new int[N];
    this->sizes = new int[N];
    for(int i=0; i<N; i++)
    {
        sets[i] = i + 1;
        sizes[i] = 1;
    }
}

UnionFind::~UnionFind()
{
    delete[] sets;
    delete[] sizes;
}

int UnionFind::size()
{
    return uf_size;
}

bool UnionFind::isInSet(int id)
{
    return (!(id <= 0 || id >= size()));
}

int UnionFind::Find(int id)
{
    if(!isInSet(id)) throw invalid();
    int root = id;
    while(root != sets[root])
        root = sets[root];
    while(id != root)
    {
        int new_id = sets[id];
        sets[id] = root;
        id = new_id;
    }
    return root;
}

void UnionFind::Union(int id1, int id2)
{
    if(!isInSet(id1) || !isInSet(id2)) throw invalid();
    int x = Find(id1), y = Find(id2);
    if(x == y) throw fail();
    if(sizes[x] < sizes[y])
    {
        sets[x] = y;
        sizes[y] += sizes[x];
    }
    else
    {
        sets[y] = x;
        sizes[x] += sizes[y];
    }
}

bool UnionFind::areConnected(int id1, int id2)
{
    return(Find(id1) == Find(id2));
}

int UnionFind::AreaSize(int id)
{
    int x = Find(id);
    return sizes[x];
}

