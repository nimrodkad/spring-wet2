#include <iostream>
#include "avl_rank.h"

using namespace std;

int main()
{
    avl_rank avl;
    avl.insert(1, 1);
    avl_rank avl1;
    avl_rank::merge(&avl, &avl1);
    return 0;
}
