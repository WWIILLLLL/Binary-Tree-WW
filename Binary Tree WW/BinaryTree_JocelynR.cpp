// BinaryTree_JocelynR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.hpp"

int main()
{
	std::cout << "Hello World!\n";

	BinaryTree<char> demoTree;

	demoTree.Insert('8');
	demoTree.Insert('5');
	demoTree.Insert('9');

	std::cout << "The height of the tree is " << demoTree.GetHeight() << endl;
	std::cout << "Inorder is : ";
	demoTree.TraverseInOrder();
	std::cout << endl;

	if (demoTree.Search('A')) {
		cout << "The value 'A' is found" << endl;
	}
	else {
		cout << "The value 'A' is not found" << endl;
	}

	if (demoTree.Search('D')) {
		cout << "The value 'D' is found" << endl;
	}
	else {
		cout << "The value 'D' is not found" << endl;
	}

	//create a binary Search tree
	BinaryTree<int> orderedList;

	orderedList.Insert(5);
	orderedList.Insert(7);
	orderedList.Insert(1);
	orderedList.Insert(10);
	orderedList.Insert(2);
	orderedList.Insert(6);
	orderedList.Insert(3);
	orderedList.Insert(9);
	orderedList.Insert(8);
	orderedList.Insert(4);

	//use the copy constructor to copy the list
	BinaryTree<int> copiedList(orderedList);
	cout << "Inorder traversal of the copied tree." << endl;
	copiedList.TraverseInOrder();
	cout << endl;
	copiedList.TraversePreOrder();
	cout << endl;
	copiedList.TraversePostOrder();
	cout << endl;

	//test that it is a deep copy
	copiedList.Insert(20);
	cout << "Inorder traversal of the copied tree after Insert into copy." << endl;
	copiedList.TraverseInOrder();
	cout << endl;
	cout << "Inorder traversal of the original tree after Insert into copy." << endl;
	orderedList.TraverseInOrder();
	cout << endl;

	//test the Search
	cout << "The value 7 does " << (orderedList.Search(7) ? "" : "not ") << "exist in the list." << endl;;
	cout << "The value 11 does " << (orderedList.Search(11) ? "" : "not ") << "exist in the list." << endl;;
	cout << "The value 20 does " << (orderedList.Search(20) ? "" : "not ") << "exist in the list." << endl;;
	cout << "The value 20 does " << (orderedList.Search(20) ? "" : "not ") << "exist in the copied list." << endl;;

	//Remove with null right SubTree
	orderedList.Remove(10);
	//Remove a leaf
	orderedList.Remove(8);
	//Remove with null left SubTree
	orderedList.Remove(2);
	//Remove with non-null SubTrees
	orderedList.Remove(7);
	//Remove the root
	orderedList.Remove(5);


	cout << "Inorder traversal after removing 10,8,2,7,& 5 of the ordered list." << endl;
	orderedList.TraverseInOrder();
	cout << endl;

	cout << "Inorder traversal of the copied tree." << endl;
	copiedList.TraverseInOrder();
	cout << endl;


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
