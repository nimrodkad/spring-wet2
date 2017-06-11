#include <iostream>
#include "avl_rank.h"

using namespace std;

int main()
{
    avl_rank avl;
    avl.insert(1, 1);
    avl_rank avl1;
    avl1.insert(2, 5);
    avl+=avl1;
    avl.print();
    avl.remove(1,1);
    avl.print();
    return 0;
}
