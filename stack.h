#include "io.h"

struct node_s {
	int val;
	node_s *prev;
};

void push(int, node_s **);
int pop(node_s **);
void print(node_s *);

int menuStack();
