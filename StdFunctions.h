#pragma once
#ifndef STDFUNCTIONS_H
#define STDFUNCTIONS_H
#include <fstream>
#include <iostream>
#include <string>
#include "Functions.h"

Node* ReadFile(const char* fileName);
Node* IncFrequency(Node* Head, char c);
void Sort(Node* Head);
Node* InsertSorted(Node* Head, Node* elt);
Node* SearchTree(Node* Tree, std::string C);
#endif