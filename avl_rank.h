#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <cstdlib>

namespace Avl_Defines
{
    const int INVALID_RANK = -1;

    const int INVALID_ID = -1;

    const int INVALID_LVL = -1;
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

    avl_rank();

    ~avl_rank();

    bool insert(int id, int lvl, int rank);

    bool remove(const int id, const int lvl, const int rank);

    int find_newest_suitable(int lvl);

    bool doesExist(int id, int rank);

    class Node
    {
    public:

        struct Info
        {

            int id;
            int lvl;
            int rank;

            Info(const int id, const int lvl, const int rank) : id(id), lvl(lvl), rank(rank) {}

            Info(const int id, const int rank) : id(id), lvl(INVALID_LVL), rank(rank) {}

        };

        int height;

        avl_rank::Node::Info info;

        Node *left, *right;

        int lvl_left, lvl_right;

        Node(int i, int l, int r) :
            height(1), info(i, l, r), left(NULL), right(NULL),
            lvl_left(INVALID_LVL), lvl_right(INVALID_LVL) {}

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

private:

    avl_rank::Node* root;

    int height(avl_rank::Node* node);

    int balance_factor(avl_rank::Node* node);

    void set_height(avl_rank::Node* node);

    avl_rank::Node* rotate_left(avl_rank::Node* node1);

    avl_rank::Node* rotate_right(avl_rank::Node* node1);

    avl_rank::Node* balance_node(avl_rank::Node* node);

    avl_rank::Node* insert(avl_rank::Node*, avl_rank::Node::Info info);

    avl_rank::Node* find_min(avl_rank::Node* node);

    avl_rank::Node* remove_min(avl_rank::Node* node);

    avl_rank::Node* remove(avl_rank::Node* node, avl_rank::Node::Info info, int* max);

    int find_newest_suitable(avl_rank::Node* node, int lvl);

    bool doesExist(avl_rank::Node* node, avl_rank::Node::Info info);

    void setLevels(avl_rank::Node *node);
};


#endif //AVL_TREE_H
