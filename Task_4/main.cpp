#include<iostream>
#include"BTree.h"

int main(int argc, char* argv[])
{
    BTree tree;
    tree.Insert(8);
    tree.Insert(4);
    tree.Insert(12);
    tree.Insert(2);
    tree.Insert(6);
    tree.Insert(10);
    tree.Insert(14);
    std::cout << tree << std::endl;
    return EXIT_SUCCESS;
}
