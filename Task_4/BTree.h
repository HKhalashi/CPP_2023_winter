#pragma once
#include<ostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
            data(data), left(left), right(right) {}
    ~Node()
    {
        //data = T();
        left = nullptr;
        right = nullptr;
    }

};
class BTree
{
private:
    Node* root;

    void Clear(Node*& node);

    void Insert(Node*& node, Node* dataNode);

    void Print(Node*& node, std::ostream& stream);

    void PrintH(Node*& node, std::ostream & stream, int depth = 0);

    void PrintV(Node*& node, std::ostream & stream);

public:
    BTree() : root(nullptr) {};

    ~BTree();

    void Insert(int data);

    friend std::ostream & operator<<(std::ostream & stream, BTree& tree);
    int max_depth(Node* node);
};
