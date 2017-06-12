#include <iostream>
#include "avl_rank.h"

using namespace std;

int Max(int x, int y)
{
    return x < y ? y : x;
}

int Max(int x, int y, int z)
{
    return Max(Max(x, y), z);
}

Compare_Options Compare(avl_rank::Node::Info info1, avl_rank::Node::Info info2)
{
    if(info1.id == info2.id) return EQUALS;
    if(info1.pwr < info2.pwr) return SMALLER;
    if(info1.pwr == info2.pwr)
        if(info1.id > info2.id)
            return SMALLER;
    return BIGGER;
}

avl_rank::avl_rank() : max_id(Avl_Defines::INVALID_ID), root(NULL), size(0), max_pwr(Avl_Defines::INVALID_PWR) {}

avl_rank::~avl_rank()
{
    if(root)
    {
        root->destroy();
        delete root;
    }
}

bool avl_rank::doesExist(int id, int pwr)
{
    avl_rank::Node::Info info(id, pwr);
    return doesExist(root, info);
}

int avl_rank::get_size()
{
    return size;
}

int avl_rank::height(avl_rank::Node* node)
{
    if(!node) return 0;
    return node->height;
}

int avl_rank::balance_factor(avl_rank::Node* node)
{
    return (height(node->left) - height(node->right));
}

void avl_rank::set_height(avl_rank::Node* node)
{
    int height_left = height(node->left), height_right = height(node->right);
    node->height = Max(height_right, height_left);
    node->height++;
}

avl_rank::Node* avl_rank::rotate_left(avl_rank::Node* node1)
{
    avl_rank::Node* node2 = node1->right;
    node1->right = node2->left;
    node2->left = node1;
    set_height(node1);
    set_height(node2);
    return node2;
}

avl_rank::Node* avl_rank::rotate_right(avl_rank::Node* node1)
{
    avl_rank::Node* node2 = node1->left;
    node1->left = node2->right;
    node2->right = node1;
    set_height(node1);
    set_height(node2);
    return node2;
}

avl_rank::Node* avl_rank::balance_node(avl_rank::Node* node)
{
    set_height(node);
    if(balance_factor(node) == -2)
    {
        if(balance_factor(node->right) > 0)
            node->right = rotate_right(node->right); // R
        return rotate_left(node); // L
    }
    if(balance_factor(node) == 2)
    {
        if(balance_factor(node->left) < 0)
            node->left = rotate_left(node->left); // L
        return rotate_right(node); // R
    }
    return node;
}

bool avl_rank::insert(int id, int pwr)
{
    avl_rank::Node::Info info(id, pwr);
    if(doesExist(root, info)) return false;
    root = insert(root, info);
    setRanks(root);
    setSizes(root);
    size++;
    if(pwr > max_pwr)
    {
        max_pwr = pwr;
        max_id = id;
    }
    return true;
}

avl_rank::Node* avl_rank::insert(avl_rank::Node* node, avl_rank::Node::Info info)
{
    if(!node)
        return new avl_rank::Node(info);
    switch(Compare(info, node->info))
    {
    case SMALLER :
        node->left = insert(node->left, info);
        break;
    case EQUALS :
    case BIGGER :
        node->right = insert(node->right, info);
        break;
    }
    return balance_node(node);
}

avl_rank::Node* avl_rank::find_max(avl_rank::Node* node)
{
    if(!node->right) return node;
    return find_max(node->right);
}

avl_rank::Node* avl_rank::find_min(avl_rank::Node* node)
{
    if(!node->left) return node;
    return find_min(node->left);
}

avl_rank::Node* avl_rank::remove_min(avl_rank::Node* node)
{
    if(!node->left)
        return node->right;
    node->left = remove_min(node->left);
    return balance_node(node);
}

bool avl_rank::remove(const int id, const int pwr)
{
    avl_rank::Node::Info info(id, pwr);
    if(!doesExist(root, info)) return false;
    root = remove(root, info);
    setRanks(root);
    setSizes(root);
    size--;
    if(size)
    {
        Node* max = find_max(root);
        max_pwr = max->info.pwr;
        max_id = max->info.id;
    }
    else
    {
        max_pwr = Avl_Defines::INVALID_PWR;
        max_id = Avl_Defines::INVALID_ID;
    }
    return true;
}

avl_rank::Node* avl_rank::remove(avl_rank::Node* node, avl_rank::Node::Info info)
{
    if(!node)
        return NULL;

    if(Compare(info, node->info) == SMALLER)
        node->left = remove(node->left, info);

    else if(Compare(info, node->info) == BIGGER)
        node->right = remove(node->right, info);

    else   // Found it
    {
        avl_rank::Node* left = node->left;
        avl_rank::Node* right = node->right;
        delete node;
        if(!right) return left;
        avl_rank::Node* min = find_min(right);
        min->right = remove_min(right);
        min->left = left;
        return balance_node(min);
    }
    return balance_node(node);
}

int node_rank(avl_rank::Node* node)
{
    return node ? node->info.tree_size : 0;
}

avl_rank::Node* avl_rank::select(int k)
{
    if(k>size) return root;
    return select(root, k);
}

avl_rank::Node* avl_rank::select(avl_rank::Node* node, int k)
{
    //if(!node) return NULL;
    if(node_rank(node->left) == k-1) return node;
    if(node_rank(node->left) > k-1) return select(node->left, k);
    return select(node->right, k-node_rank(node->left)-1);
}

bool avl_rank::doesExist(avl_rank::Node* node, avl_rank::Node::Info info)
{
    if(!node) return false;
    switch(Compare(info, node->info))
    {
    case SMALLER :
        return doesExist(node->left, info);
        break;
    case BIGGER :
        return doesExist(node->right, info);
        break;
    case EQUALS :
    default :
        return true;
    }
}

void avl_rank::setRanks(avl_rank::Node *node)
{
    if(!node)
        return;
    setRanks(node->left);
    setRanks(node->right);
    node->info.rank = node->info.pwr + (node->left ? node->left->info.rank : 0) + (node->right ? node->right->info.rank : 0);
}

void avl_rank::setSizes(avl_rank::Node *node)
{
    if(!node) return;
    setSizes(node->left);
    setSizes(node->right);
    node->info.tree_size = 1 + (node->left ? node->left->info.tree_size : 0) + (node->right ? node->right->info.tree_size : 0);
}

void avl_rank::addToArray(avl_rank::Node* node, Node::Info array[], int* i)
{
    if(!node) return;
    addToArray(node->left, array, i);
    array[*i] = node->info;
    (*i)++;
    addToArray(node->right, array, i);
}

void merge_sort(avl_rank::Node::Info array1[], avl_rank::Node::Info array2[], avl_rank::Node::Info result[], int size1, int size2)
{
    if(!size1 && !size2) return;
    if(!size1)
    {
        for(int i=0; i<size2; i++) result[i]=array2[i];
        return;
    }
    if(!size2)
    {
        for(int i=0; i<size1; i++) result[i]=array1[i];
        return;
    }
    switch(Compare(array1[size1-1], array2[size2-1]))
    {
    case SMALLER:
        result[size1+size2-1] = array2[size2-1];
        merge_sort(array1, array2, result, size1, size2-1);
        break;
    case EQUALS:
    case BIGGER:
        result[size1+size2-1] = array1[size1-1];
        merge_sort(array1, array2, result, size1-1, size2);
        break;
    }

    // In our project equality is not possible
}

avl_rank::Node* avl_rank::make_tree(avl_rank::Node::Info array[], int start, int end)
{
    if(start>end) return NULL;
    int middle = (start + end)/2;
    Node* node = new Node(array[middle]);
    node->left = make_tree(array, start, middle-1);
    node->right = make_tree(array, middle+1, end);
    return balance_node(node);
}

void avl_rank::operator+=(avl_rank& tree)
{
    root = merge(root, size, tree.root, tree.size);
    setRanks(root);
    setSizes(root);
    size+=tree.size;
}

avl_rank::Node* avl_rank::merge(avl_rank::Node* node1, int size1, avl_rank::Node* node2, int size2)
{
    if((!node1 && !node2) || (!node1->height && !node2->height)) return NULL;
    if(!size1) return node2;
    if(!size2) return node1;
    Node::Info* array1 = new Node::Info[size1];
    Node::Info* array2 = new Node::Info[size2];
    int i=0;
    addToArray(node1, array1, &i);
    i=0;
    addToArray(node2, array2, &i);
    Node::Info* result = new Node::Info[size1+size2];
    merge_sort(array1, array2, result, size1, size2);
    Node* tree = make_tree(result, 0, size1+size2-1);
    delete[] array1;
    delete[] array2;
    delete[] result;
    return tree;
}

int avl_rank::lowestCommonAncestor(avl_rank::Node* node, avl_rank::Node* last)
{
	int lcaNode = Avl_Defines::INVALID_RANK;
	int pathSize=(ceil(log2(size))+1);
	avl_rank::Node **path1=new avl_rank::Node *[pathSize];
	avl_rank::Node **path2=new avl_rank::Node *[pathSize];
	for(int i=0;i<pathSize;i++)
    {
		path1[i]=NULL;
		path2[i]=NULL;
	}
	getPath(node,path1);
	getPath(last,path2);
	for(int i=0;i<pathSize;i++)
	{
		if(!(Compare(path1[i]->info, path2[i]->info)==EQUALS))
		{ 	//first different node in both paths
			lcaNode = path1[i-1]->info.rank;		//the preior node is the Lca node
			break;
		}
	}
	if(lcaNode == Avl_Defines::INVALID_RANK)
	{		//lca node is the last node
		lcaNode=path1[pathSize-1]->info.rank;
	}
	for(int i=0;i<pathSize;i++)
    {
		if(path1[i]) delete path1[i];
		if(path2[i]) delete path2[i];
	}
	delete []path1;
	delete []path2;
	return lcaNode;
}


//writing the search path of a given node to the nodesArray
void avl_rank::getPath(avl_rank::Node *node, avl_rank::Node **nodesArray)
{
	avl_rank::Node *currentNode=root;
	int counter=0;
	while(!(Compare(currentNode->info, node->info) == EQUALS))
    {
		nodesArray[counter++]=new avl_rank::Node(currentNode->info);
		if(((currentNode->left == NULL) && (currentNode->right != NULL)) || Compare(currentNode->left->info, node->info) == SMALLER )
			currentNode=currentNode->right;
		else
			currentNode=currentNode->left;
	}
	nodesArray[counter++]=new avl_rank::Node(currentNode->info);
}

void avl_rank::print()
{
    print(root);
}

avl_rank::Node* avl_rank::get_root()
{
    return root;
}

void avl_rank::print(avl_rank::Node* node)
{
    if(!node) return;
    print(node->left);
    std::cout << "id " << node->info.id << " pwr " << node->info.pwr << " sum_power "  << node->info.rank << " tree_size " << node->info.tree_size << std::endl;
    print(node->right);
}
