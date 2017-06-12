#include <iostream>
#include "avl_rank.h"

using namespace std;

int sumOfPower(avl_rank* tree,int num)
{
	int treeSize=tree->get_size();
	if(!treeSize) return 0;
	if(num >= treeSize) return tree->get_root()->info.rank;
	avl_rank::Node* node=tree->select(treeSize-num+1);
	avl_rank::Node* last=tree->select(treeSize);
	int commonAncestor=tree->lowestCommonAncestor(node,last);
	if(node->left) return (commonAncestor - (node->left->info.rank));
	return commonAncestor;
}

int main()
{
    avl_rank avl;
    avl.insert(1, 1);
    avl.insert(2, 1);
    avl.insert(3, 1);
    avl.insert(4, 1);
    avl.insert(5, 1);
    avl.insert(6, 1);
    avl.insert(7, 1);
    avl_rank avl1;
    avl1.insert(2, 1);
    avl.print();
    cout << sumOfPower(&avl, 6) << endl;
    avl.print();
    return 0;
}
