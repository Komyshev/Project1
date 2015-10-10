#include <iostream>
using namespace std;

struct node_q {
	int val;
	node_q *next;
};

void add(int, node_q **, node_q **);
int del(node_q **);
void print(node_q *);
