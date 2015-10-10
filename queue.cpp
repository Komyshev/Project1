#include "queue.h"

void add(int val, node_q **end, node_q **st)
{
     node_q *var = new node_q;
	 (*var).val = val;
	 (*var).next = NULL;
     if (*end != NULL) (**end).next = var;
     else *st = var;
     *end = var;
}

int del(node_q **st)
{
    int temp = (**st).val;
    node_q *t = (**st).next;
    delete *st;
    *st = t;
    return temp;
}

void print(node_q *st)
{
     while (st != NULL)
     {
			  cout << (*st).val << " ";
			  st = (*st).next;
     }             
}
 
