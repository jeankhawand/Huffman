#include "StdFunctions.h"

using namespace std;

Node *InsertAtHead(Node *Head, Node *ToInsert)
{
	ToInsert->next = Head;
	Head = ToInsert;
	return Head;
}

Node *InsertBetween(Node *before, Node *after, Node *ToInsert)
{
	ToInsert->next = after;
	before->next = ToInsert;
	return before;
}

Node *IncFrequency(Node *Head, char c)
{
	// This function searches for the character C in the simply linked list.
	// If it was able to find a node containing this character, it increments it frequency by 1.
	// If no such node exists, it creates a new node and append it to the beginning of the simply linked list, where :
	//		the 'txt' field is equal to the character
	//		the 'frequnecy' field is equal to 1
	//		the 'parent', 'left' and 'right' fields are set to NULL
	Node *cur = new Node;
	cur = Head;
	while (cur != NULL)
	{
		if (cur->txt[0] == c)
		{
			cur->frequency++;
			return Head;
		}
		cur = cur->next;
	}

	Node *temp = new Node;
	temp->next = Head;
	temp->txt = c;
	temp->frequency = 1;
	Head = temp;
	return Head;
}

Node *ReadFile(const char *fileName)
{
	// This function reads a file given by its name.
	// It creates a simply linked list containing the letters present in the file along with their frequency of occurence.
	// You can use the previous function : Node* IncFrequency(Node* Head, char c)
	ifstream file(fileName);
	Node *Head = new Node;
	Head = NULL;
	char c = 'a';
	string line;
	getline(file, line);
	for (int i = 0; c != '\0'; i++)
	{
		while (line[i] == ' ')
		{
			i++;
		}
		c = line[i];
		if (c != '\0')
		{
			Head = IncFrequency(Head, c);
		}
	}
	return Head;
}

void Sort(Node *Head)
{
	// This function sorts the simply linked list in ascending order using the Selection Sort algorithm.
	// For this purpose, you may use the already defined function : int compare(Node* First, Node* Second)
	// The compare function compares two nodes according to their frequencies and lexicographic order.
	// The compare function returns -1 if the first node is smaller than the second node.
	// The compare function returns +1 if the first node is larger than the second node.
	// The compare function returns 0 if both nodes are equal.
	Node *Min = new Node;
	Node *cur1 = new Node;
	Node *cur2 = new Node;
	Min = Head;
	for (cur1 = Head; cur1->next != NULL; cur1 = cur1->next)
	{
		for (cur2 = cur1; cur2 != NULL; cur2 = cur2->next)
		{
			if (1 == compare(Min, cur2))
			{
				Min = cur2;
			}
		}
		int swappingFrequency = Min->frequency;
		string swappingTxt = Min->txt;

		Min->frequency = cur1->frequency;
		Min->txt = cur1->txt;

		cur1->frequency = swappingFrequency;
		cur1->txt = swappingTxt;
	}
}

Node *InsertSorted(Node *Head, Node *elt)
{
	// This function inserts the node elt in the simply linked list while keeping the list
	// sorted according to the frequencies of occurrence and the lexicographic order.
	// For this purpose, you may use the already defined function : int compare(Node* First, Node* Second)
	if (Head == NULL)
	{
		Head = elt;
		return Head;
	}

	if (Head->next == NULL)
	{
		if (1 == compare(Head, elt))
		{
			InsertAtHead(Head, elt);
			return Head;
		}
		else
		{
			Head->next = elt;
			return Head;
		}
	}

	Node *cur1 = new Node;
	Node *cur2 = new Node;
	cur1 = Head;
	cur2 = Head->next;

	if (1 == compare(Head, elt))
	{
		InsertAtHead(Head, elt);
		return Head;
	}
	while (cur2 != NULL)
	{
		if (1 == compare(cur2, elt))
		{
			InsertBetween(cur1, cur2, elt);
			return Head;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	InsertBetween(cur1, cur2, elt);
	return Head;
}

Node *SearchTree(Node *Tree, string C)
{
	// This function searchs the binary tree for the node containing the character C.
	// It returns the a pointer to the node if such node exists
	// or NULL if the character does not occur in the text
	if (Tree->txt == C)
	{
		return Tree;
	}
	if (Tree->left->txt.find(C) != string::npos)
	{
		return SearchTree(Tree->left, C);
	}

	if (Tree->right->txt.find(C) != string::npos)
	{
		return SearchTree(Tree->right, C);
	}
	if (Tree == NULL) return NULL;
	return NULL;
}
