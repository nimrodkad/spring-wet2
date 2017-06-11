#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <cstdlib>

namespace Avl_Defines
{
    const int INVALID_SIZE = 0;

    const int INVALID_RANK = 0;

    const int INVALID_PWR = 0;

    const int INVALID_ID = -1;
}

using namespace Avl_Defines;

enum Compare_Options
{
    SMALLER,
    EQUALS,
    BIGGER
};

class avl_rank
{
public:

    class Node
    {
    public:

        struct Info
        {

            int id;
            int pwr;
            int rank;
            int tree_size;

            Info() {}

            Info(const int id, const int pwr) : id(id), pwr(pwr), rank(Avl_Defines::INVALID_RANK) {}

            Info(const int id, const int pwr, const int rank) : id(id), pwr(pwr), rank(rank) {}

            Info(Info& info) : id(info.id), pwr(info.pwr), rank(info.rank), tree_size(info.tree_size) {}

            //Info& operator=(const Info& info) {id = info.id; pwr = info.pwr; rank = info.rank; tree_size = info.tree_size;}

        };

        int height;

        avl_rank::Node::Info info;

        Node *left, *right;

        Node(int i, int p) :
            height(1), info(i, p), left(NULL), right(NULL){}

        Node(int i, int p, int r) :
            height(1), info(i, p, r), left(NULL), right(NULL){}

        Node(Info info) :
            height(1), info(info.id, info.pwr, info.rank), left(NULL), right(NULL){}

        ~Node() {}

        void destroy()
        {
            if(left)
            {
                left->destroy();
                delete left;
            }
            if(right)
            {
                right->destroy();
                delete right;
            }
        }
    };

    int max_id;

    avl_rank();

    ~avl_rank();

    bool insert(int id, int pwr);

    bool remove(const int id, const int pwr);

    void operator+=(avl_rank& tree);

    bool doesExist(int id, int pwr);

    int get_size();

    avl_rank::Node* select(int k);

    void print();

private:

    avl_rank::Node* root;

    int size;

    int max_pwr;

    int height(avl_rank::Node* node);

    int balance_factor(avl_rank::Node* node);

    void set_height(avl_rank::Node* node);

    avl_rank::Node* rotate_left(avl_rank::Node* node1);

    avl_rank::Node* rotate_right(avl_rank::Node* node1);

    avl_rank::Node* balance_node(avl_rank::Node* node);

    avl_rank::Node* insert(avl_rank::Node*, avl_rank::Node::Info info);

    avl_rank::Node* find_max(avl_rank::Node* node);

    avl_rank::Node* find_min(avl_rank::Node* node);

    avl_rank::Node* remove_min(avl_rank::Node* node);

    avl_rank::Node* remove(avl_rank::Node* node, avl_rank::Node::Info info);

    avl_rank::Node* select(avl_rank::Node* node, int k);

    bool doesExist(avl_rank::Node* node, avl_rank::Node::Info info);

    void setRanks(avl_rank::Node *node);

    void setSizes(avl_rank::Node *node);

    void addToArray(avl_rank::Node* node, avl_rank::Node::Info array[], int* i);

    avl_rank::Node* make_tree(avl_rank::Node::Info array[], int start, int end);

    avl_rank::Node* merge(avl_rank::Node* node1, int size1, avl_rank::Node* node2, int size2);

    void print(avl_rank::Node* node);
};


#endif //AVL_TREE_H
