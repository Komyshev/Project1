#include "io.h"

struct node_doublyLinkedList{
	int val;
	node_doublyLinkedList *next;
	node_doublyLinkedList *prev;
	node_doublyLinkedList()
	{
		next = NULL;
		prev = NULL;
	}
};

void addBegin(int, node_doublyLinkedList *&, node_doublyLinkedList *&);

void addEnd(int, node_doublyLinkedList *&, node_doublyLinkedList *&);

int addAfter(int, int, node_doublyLinkedList *, node_doublyLinkedList *&);

int addBefore(int, int, node_doublyLinkedList *&, node_doublyLinkedList *);

int erase(int, node_doublyLinkedList *&, node_doublyLinkedList *&);

int sorting(node_doublyLinkedList *&, node_doublyLinkedList *&);

void print(node_doublyLinkedList *);

void printConversely(node_doublyLinkedList *);

int menuDoublyLinkedList();

int debug();