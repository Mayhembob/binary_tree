//============================================================================
// Name        : binary_tree1.cpp
// Author      : Lev Stefanovich
// Description : Some exercies for learning binary trees
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------

// A node contains an integer 'data', and two pointers that point to
// other nodes.
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// When a new node is created, it contains data that was passed to the
// constructor and its left and right pointers are initialized to NULL.
// Those pointers will later point to other nodes as more are created.
struct node* newNode(int data) {
	struct node* node = new(struct node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// The insert method takes an int 'data' and a pointer 'node' to an existing
// binary tree. Then a new node is created in the tree with the rule that
// left branches of any node contain smaller values and right branches
// contain larger values.
struct node* insert(struct node* node, int data) {
	if ( node == NULL )
		// If the node is NULL, we have reached the end of a tree.
		// In that case, we make a new node at this location and put 'data' as
		// the new node's data
		return newNode(data);
	else {
		// If the data we are trying to insert is less than the current node,
		// we go left, otherwise we go right. Keep going until
		// we find a NULL node.
		if ( data <= node->data )
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
	return(node);
}

// Recursively computes the size of the binary tree.
// Size is the number of (non NULL) nodes in the tree.
// This if a node is NULL, it returns 0 (not adding to the size),
// Otherwise it returns 1 (its size) plus the size of all the nodes to the left
// and all the nodes to the right.
int size(struct node* node) {
	if (node == NULL)
		return 0;
	return 1 + size(node->left) + size(node->right);
}

// This is similar to the size() function, but it only returns the larger
// of the left or the right branch, which yields the max depth.
int maxDepth(struct node* node) {
	if (node == NULL)
		return 0;
	if (maxDepth(node->left) < maxDepth(node->right))
		return 1 + maxDepth(node->right);
	return 1 + maxDepth(node->left);
}

int minValue(struct node* node) {
	if ( node->left == NULL )
		return node->data;
	return minValue(node->left);
}

void printTreeAsList(struct node* node) {
	if(node->left) printTreeAsList(node->left);
	cout << node->data << " ";
	if(node->right) printTreeAsList(node->right);
}

void printPostorder(struct node* node) {
	if(node->left) {
		//cout << " going left ";
		printPostorder(node->left);
	}
	if(node->right) {
		//cout << "going right";
		printPostorder(node->right);
	}
	cout << node->data << " ";
}

bool isLeaf(struct node* node) {
	if (node->left == NULL && node->right == NULL)
		return true;
	else
		return false;
}

int pathSumHelper(struct node* node, int sum, int runningTotal) {
	runningTotal += node->data;
	if (isLeaf(node)) {
		if (sum == runningTotal)
			return 1;
		else
			return 0;
	}
	return pathSumHelper(node->left, sum, runningTotal) + pathSumHelper(node->right, sum, runningTotal);
}

bool hasPathSum(struct node* node, int sum) {
	int pathsMatch = 0;
	pathsMatch = pathSumHelper(node, sum, 0);
	if (pathsMatch)
		return true;
	else
		return false;
}

void printArray(int arr[], int len) {
	for (int i = 0 ; i < len ; i++) {
		cout << arr[i] << " ";
	}
}

void copyArray(int arrA[], int arrB[], int lengthA) {
	// Copies A into B
	for (int i = 0 ; i < lengthA ; i++) {
		arrB[i] = arrA[i];
	}
}

void printPathsRecur(struct node* node, int path[], int pathLen) {
	// Path array communicates sequence that led up to current call
	if (node == NULL)
		return;
	int *newPath = new int[pathLen+1];
	copyArray(path, newPath, pathLen);
	newPath[pathLen] = node->data;
	pathLen++;

}

void printNodeDetailed(struct node* root) {
	cout << "top: "   << root->data   << "\n";

	cout << "left: ";
	if( (root->left) )
		cout << (root->left)->data  << "\n";
	else
		cout << "NULL\n";

	cout << "right: ";
	if ( (root->right) )
		cout << (root->right)->data << "\n";
	else
		cout << "NULL\n";
	cout << endl;
}

void printTreeDetailed(struct node* node) {
	if (node == NULL)
		return;
	printNodeDetailed(node);
	printTreeDetailed(node->left);
	printTreeDetailed(node->right);
}

void printPicture(struct node* node) {
	if (maxDepth(node) > 4) {
		cout << "This binary tree is too large to print, sorry!\n";
		return;
	}
	if (maxDepth(node) == 0) {
		cout << "This tree is empty!\n";
		return;
	}
	if (maxDepth(node) == 1) {
		cout << node->data;
	}
	if (maxDepth(node) == 2 ) {

	}
}


int main() {

	vector<int> myVector;
	myVector.push_back(5);
	cout << myVector.back();

	/*
	// method using 1 pointer
	node* node2 = newNode(2);
	node2->left = newNode(1);
	node2->right = newNode(3);


	cout << "top: "   << node2->data   << "\n"
         << "left: "  << (node2->left)->data  << "\n"
         << "right: " << (node2->right)->data << endl;


	// method using calls to insert
	node* root = NULL;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 9);

	// printPostorder(root);
	 cout << endl;
	 printTree(root);
	*/
	/*
	cout << "top: "   << root->data   << "\n"
	     << "left: "  << (root->left)->data  << "\n"
	     << "right: " << (root->right)->data << endl;
	*/

	/*
	cout << "size: " << size(root) << endl;
	cout << "depth: "  << maxDepth(root) << endl;
	cout << "min: " << minValue(root) << endl;
	*/
	/*
	bool match;
	int userEntry;

	do {
		cout << "Enter an integer: ";
		cin >> userEntry;

		match = hasPathSum(root, userEntry);
		if (match) {
			cout << "The tree does have that path sum" << endl;
			cout << endl;
		}
		else {
			cout << "No match" << endl;
			cout << endl;
		}
	} while (userEntry != -1);
*/


}
