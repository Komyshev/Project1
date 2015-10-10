#include "stack.h"

void push(int val, node_s **top)
{
	node_s *var = new node_s;
	var->val = val;
	var->prev = *top;
	*top = var;
}

int pop(node_s **top)
{
	int val = (*top)->val;
	node_s *p = (*top)->prev;
	delete *top;
	*top = p;
	return val;
}

void print(node_s *top)
{
	while (top != NULL)
	{
		cout << top->val << " ";
		top = top->prev;
	}
}
