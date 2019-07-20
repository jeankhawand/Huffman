#include "Functions.h"

int compare(Node* First, Node* Second) {
	if (First->frequency < Second->frequency) return -1;
	if (First->frequency > Second->frequency) return 1;
	if (First->txt < Second->txt) return -1;
	if (First->txt > Second->txt) return 1;
	return 0;
}

Node* Initialize() {
	return NULL;
}

void DisplayList(Node* Head) {
	std::cout << std::endl;
	for (Node* curr = Head; curr != NULL; curr = curr->next) {
		std::cout << curr->txt << " : " << curr->frequency << std::endl;
	}
	std::cout << std::endl;
}

void DisplayTree(Node* Tree, Node* charNode) {
	if (Tree == NULL || charNode == NULL)	return;

	Stack* S = Create();
	Node* curr = charNode, *parent;
	while (curr != NULL && curr->parent != NULL) {
		parent = curr->parent;
		if (parent->left == curr)	S = push(S, 0);
		else						S = push(S, 1);
		curr = parent;
	}
	int x;
	std::cout << charNode->txt << " : ";
	while (!isEmpty(S)) {
		S = pop(S, &x);
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

Node* Encode(Node* Tree) {
	if (Tree == NULL || Tree->next == NULL) return Tree;

	Node *newTree = Tree->next->next;
	Node* newNode = new Node;
	newNode->frequency = Tree->frequency + Tree->next->frequency;
	newNode->txt = Tree->txt + Tree->next->txt;
	newNode->left = Tree;
	newNode->right = Tree->next;
	newNode->parent = NULL;
	newNode->next = NULL;
	Tree->parent = newNode;
	Tree->next->parent = newNode;

	newTree = InsertSorted(newTree, newNode);
	return newTree;
}

Node* HuffmanTree(Node* Tree) {
	while (Tree != NULL && Tree->next != NULL) {
		Tree = Encode(Tree);
	}
	return Tree;
}