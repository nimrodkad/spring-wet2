#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <cstdlib>

namespace Avl_Defines
{
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

    avl_rank();

    ~avl_rank();

    bool insert(int id, int pwr);

    bool remove(const int id, const int pwr);

    static void merge(avl_rank* tree1, avl_rank* tree2);

    //int get_strongest(int pwr);

    bool doesExist(int id, int pwr);

    int get_size();

    class Node
    {
    public:

        struct Info
        {

            int id;
            int pwr;
            int rank;

            Info() {}

            Info(const int id, const int pwr) : id(id), pwr(pwr), rank(Avl_Defines::INVALID_RANK) {}

            Info(const int id, const int pwr, const int rank) : id(id), pwr(pwr), rank(rank) {}

            Info(Info& info) : id(info.id), pwr(info.pwr), rank(info.rank) {}

            Info& operator=(const Info& info) {id = info.id; pwr = info.pwr; rank = info.rank;}

        };

        int height;

        avl_rank::Node::Info info;

        Node *left, *right;

        int rank_left, rank_right;

        Node(int i, int p) :
            height(1), info(i, p), left(NULL), right(NULL),
            rank_left(INVALID_RANK), rank_right(INVALID_RANK) {}

        Node(int i, int p, int r) :
            height(1), info(i, p, r), left(NULL), right(NULL),
            rank_left(INVALID_RANK), rank_right(INVALID_RANK) {}

        Node(Info info) :
            height(1), info(info.id, info.pwr, info.rank), left(NULL), right(NULL),
            rank_left(INVALID_RANK), rank_right(INVALID_RANK) {}

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

    int size;

    int max_id;

    int max_pwr;

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

    avl_rank::Node* remove(avl_rank::Node* node, avl_rank::Node::Info info);

    //int get_strongest(avl_rank::Node* node, int pwr);

    bool doesExist(avl_rank::Node* node, avl_rank::Node::Info info);

    void setRanks(avl_rank::Node *node);

    void addToArray(avl_rank::Node* node, avl_rank::Node::Info array[], int* i);

    avl_rank::Node* make_tree(avl_rank::Node::Info array[], int start, int end);

    avl_rank::Node* merge(avl_rank::Node* node1, int size1, avl_rank::Node* node2, int size2);
};


#endif //AVL_TREE_H
