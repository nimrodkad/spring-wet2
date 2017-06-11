#include "UnionFind.h"

UnionFind::UnionFind(int N) : uf_size(N)
{
    if(N <= 0) throw fail();
    this->sets = new int[N+1];
    this->sizes = new int[N+1];
    this->wins = new int[N+1];
    for(int i=0; i<N+1; i++)
    {
        sets[i] = i;
        sizes[i] = 1;
        wins[i] = 0;
    }
}

UnionFind::~UnionFind()
{
    delete[] sets;
    delete[] sizes;
    delete[] wins;
}

int UnionFind::size()
{
    return uf_size;
}

int UnionFind::size(int id)
{
	return sizes[Find(id)];
}

bool UnionFind::isInSet(int id)
{
    return (!(id <= 0 || id > size()));
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
        wins[y] += wins[x];
    }
    else
    {
        sets[y] = x;
        sizes[x] += sizes[y];
        wins[x] += wins[y];
    }
}

bool UnionFind::areConnected(int id1, int id2)
{
    return(Find(id1) == Find(id2));
}

int UnionFind::get_wins(int id)
{
    return wins[Find(id)];
}

void UnionFind::update_wins(int id)
{
    wins[Find(id)]++;
}

