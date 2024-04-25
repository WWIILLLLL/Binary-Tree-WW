// Binary Tree WW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.hpp"
#include "random"

using namespace std;

int main2()
{
    BinaryTree<char> tree;
    cout << "Tree height: " << tree.GetHeight() << endl;

    for (int i = 0; i < 100; i++) {
        tree.Insert('A' + (rand() % 26));
    }

    cout << "Tree height: " << tree.GetHeight() << endl;
    tree.TraverseInOrder();

    return 0;
}
