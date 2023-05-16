#include "BTree.h"
#include <queue>
void BTree::Clear(Node*& node)
{
    if (node == nullptr) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
}

void BTree::Insert(Node*& node, Node* dataNode)
{
    if (node == nullptr)
    {
        node = dataNode;
    }
    else if (node->data < dataNode->data)
    {
        Insert(node->right, dataNode);
    }
    else if (node->data > dataNode->data)
    {
        Insert(node->left, dataNode);
    }
    else
    {
        delete dataNode;
    }
}

void BTree::Insert(int data)
{
    Insert(root, new Node(data));
}

void BTree::Print(Node*& node, std::ostream & stream)
{
    if (node == nullptr)
    {
        return;
    }
    Print(node->left, stream);
    stream << node->data << " ";
    Print(node->right, stream);
}

void BTree::PrintH(Node*& node, std::ostream & stream, int depth)
{
    if (node == nullptr)
    {
        return;
    }
    PrintH(node->right, stream, depth + 1);
    for (int i = 0; i < depth; ++i)
    {
        stream << "\t";
    }
    stream << node->data << std::endl;
    PrintH(node->left, stream, depth + 1);
}

void BTree::PrintV(Node*& node, std::ostream & stream)
{
    if (node == nullptr) return;

    // max width of number
    int maxWidth = 10;
    int maxDepth = max_depth(node);
    std::queue<std::pair<Node*, int>> q;

    // push root node to queue
    q.push({node, (1 << maxDepth) * maxWidth});

    while (!q.empty()) {
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++) {
            Node* n = q.front().first;
            int space = q.front().second;
            q.pop();

            // print space before number
            for (int i = 0; i < space/2; i++)
                stream << " ";

            // print number
            if (n) {
                stream << n->data;
                // push child nodes to queue
                if(n->left) q.push({n->left, space / 2});
                if(n->right) q.push({n->right, space / 2});
            }

            // print space after number
            for (int i = 0; i < space/2; i++)
                stream << " ";
        }
        stream << "\n";
        if (maxDepth > 1) {
            maxDepth--;
        }
    }
}

int BTree::max_depth(Node* node) {
    if (node == nullptr)
        return 0;
    else {
        int lDepth = max_depth(node->left);
        int rDepth = max_depth(node->right);
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

BTree::~BTree() {
    Clear(root);
    root = nullptr;
}

std::ostream & operator<<(std::ostream & stream, BTree& tree)
{
    stream << "print" << std::endl;
    tree.Print(tree.root, stream);

    stream << std::endl << "print horizontal" << std::endl;
    tree.PrintH(tree.root, stream);

    stream << std::endl << "print vertical" << std::endl;
    tree.PrintV(tree.root, stream);


    return stream;
}
