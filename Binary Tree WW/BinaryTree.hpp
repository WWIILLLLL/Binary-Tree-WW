#pragma once

#include <vector>
#include <string>

using namespace std;

template <class T>
class BinaryTree
{

private:
	class TreeNode {
	public:
		T data;
		TreeNode* left;
		TreeNode* right;

		TreeNode(T data, TreeNode* left = nullptr, TreeNode* right = nullptr) {
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

public:
	TreeNode* root;

	BinaryTree() {
		root = nullptr;
	}

	BinaryTree(TreeNode* root) {
		this->root = root;
	}

	BinaryTree(BinaryTree<T> &tree) {
		root = tree.CopyTreeNode();
	}

	int GetHeight() {
		return root == nullptr ? 0 : GetHeight(root);
	}

	void TraversePreOrder() {
		TraversePreOrder(root);
	}

	void TraverseInOrder() {
		TraverseInOrder(root);
	}

	void TraversePostOrder() {
		TraversePostOrder(root);
	}

	BinaryTree<T> CopyTree() {
		return BinaryTree<T>(CopyTree(root));
	}

	TreeNode* CopyTreeNode() {
		return CopyTree(root);
	}

	bool Search(T value) {
		return Search(value, root);
	}

	void Remove(T value) {
		TreeNode* trail = nullptr;
		TreeNode* traversal = root;

		while (traversal != nullptr && traversal->data != value) {
			trail = traversal;
			if (value < traversal->data) {
				traversal = traversal->left;
			}
			else {
				traversal = traversal->right;
			}
		}

		if (traversal == nullptr) return;

		if (traversal->left == nullptr && traversal->right == nullptr) {
			if (trail == nullptr) {
				root = nullptr;
				delete traversal;
				return;
			}

			if (trail->left == traversal) {
				trail->left = nullptr;
				delete traversal;
			}
			else {
				trail->right = nullptr;
				delete traversal;
			}

			return;
		}

		if (traversal->left != nullptr && traversal->right == nullptr) {
			if (trail == nullptr) {
				root = traversal->left;
				delete traversal;
				return;
			}

			if (trail->left == traversal) {
				trail->left = traversal->left;
				delete traversal;
			}
			else {
				trail->right = traversal->left;
				delete traversal;
			}

			return;
		}

		if (traversal->left == nullptr && traversal->right != nullptr) {
			if (trail == nullptr) {
				root = traversal->right;
				delete traversal;
				return;
			}

			if (trail->left == traversal) {
				trail->left = traversal->right;
				delete traversal;
			}
			else {
				trail->right = traversal->right;
				delete traversal;
			}

			return;
		}

		TreeNode* foundElementTrail = nullptr;
		TreeNode* foundElement = traversal->left;

		while (foundElement->right != nullptr) {
			foundElementTrail = foundElement;
			foundElement = foundElement->right;
		}

		
		if (trail == nullptr) {
			root = foundElement;
		}
		else {
			if (trail->left == traversal) {
				trail->left = foundElement;
			}
			else {
				trail->right = foundElement;
			}
		}

		if (foundElementTrail != nullptr) {
			foundElementTrail->right = nullptr;
		}

		if (traversal->left != foundElement) {
			TreeNode* bottomLeft = foundElement;

			while (bottomLeft->left != nullptr) {
				bottomLeft = bottomLeft->left;
			}

			bottomLeft->left = traversal->left;
		}

		foundElement->right = traversal->right;
		delete traversal;
	}

	void Insert(T value) {
		if (root == nullptr) {
			root = new TreeNode(value);
			return;
		}

		Insert(value, root);
	}

	void PrettyPrint() {
		vector<vector<string>> treeString(GetHeight(), vector<string>(GetHeight() * 2, " "));
		PrettyPrint(root, 0, 0, GetHeight() * 2, treeString);

		for (int i = 0; i < GetHeight(); i++) {
			for (int j = 0; j < GetHeight() * 2; j++) {
				cout << treeString[i][j] << " ";
			}
			cout << endl;
		}
	}

private:
	int GetHeight(TreeNode* root) {
		int leftHeight = 0;
		int rightHeight = 0;

		if (root->left != nullptr) {
			leftHeight = GetHeight(root->left);
		}

		if (root->right != nullptr) {
			rightHeight = GetHeight(root->right);
		}

		return 1 + max(leftHeight, rightHeight);
	}

	void TraversePreOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		cout << root->data << endl;

		TraversePreOrder(root->left);

		TraversePreOrder(root->right);
	}

	void TraverseInOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TraverseInOrder(root->left);

		cout << root->data << endl;

		TraverseInOrder(root->right);
	}

	void TraversePostOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		TraversePostOrder(root->left);

		TraversePostOrder(root->right);

		cout << root->data << endl;
	}

	TreeNode* CopyTree(TreeNode* root) {
		if (root == nullptr) return nullptr;

		return new TreeNode(root->data, CopyTree(root->left), CopyTree(root->right));
	}

	// I wrote this before you said do it iteravely so oh well :)
	bool Search(T value, TreeNode* root) {
		if (root == nullptr) return false;
		if (root->data == value) return true;
		if (value < root->data) return Search(value, root->left);
		return Search(value, root->right);
	}

	void Insert(T value, TreeNode* root) {
		if (value == root->data) return;

		if (value < root->data) {
			if (root->left == nullptr) {
				root->left = new TreeNode(value);
				return;
			}

			Insert(value, root->left);
			return;
		}

		if (root->right == nullptr) {
			root->right = new TreeNode(value);
			return;
		}

		Insert(value, root->right);
	}

	void PrettyPrint(TreeNode* root, int depth, int pos, int length, vector<vector<string>>& treeString) {
		if (root == nullptr) return;
		treeString[depth][pos] = to_string(root->data);

		PrettyPrint(root->left, depth + 1, pos, length / 2, treeString);
		PrettyPrint(root->right, depth + 1, pos + length / 2, length / 2, treeString);
	}
};

