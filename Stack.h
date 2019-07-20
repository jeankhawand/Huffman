#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	int data;
	Stack* next;
};

Stack* Create();
bool isEmpty(Stack* S);
Stack* push(Stack* S, int val);
Stack* pop(Stack *S, int *res);
#endif