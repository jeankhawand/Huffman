#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include "Stack.h"

struct Node {
	int frequency;
	std::string txt;
	Node* next;
	Node* left;
	Node* right;
	Node* parent;
};

extern Node* InsertSorted(Node* Head, Node* elt);

int compare(Node* First, Node* Second);
Node* Initialize();
void DisplayList(Node* Head);
void DisplayTree(Node* Tree, Node* charNode);
Node* Encode(Node* Tree);
Node* HuffmanTree(Node* Tree);
#endif