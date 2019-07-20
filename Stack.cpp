#include "Stack.h"

Stack* Create() {
	return NULL;
}

bool isEmpty(Stack* S) {
	return (S == NULL);
}

Stack* push(Stack* S, int val) {
	Stack* elt = new Stack;
	elt->data = val;
	elt->next = S;
	return elt;
}

Stack* pop(Stack *S, int *res) {
	if (S == NULL) return S;
	*res = S->data;
	Stack* tmp = S->next;
	delete S;
	return tmp;
}