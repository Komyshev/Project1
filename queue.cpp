#include "queue.h"

void add(int val, node_q **start, node_q **end)
{
     node_q *var = new node_q;

	 var->val = val;
	 var->next = NULL;

	 if (*end)
	 {
		 (*end)->next = var;
	 }
	 else
	 {
		 *start = var;
	 }

     *end = var;
}

int del(node_q **start)
{
    int temp = (*start)->val;
	node_q *t = (*start)->next;
    
	delete *start;
    *start = t;
    
	return temp;
}

void print(node_q *start)
{
	if (!start)
	{
		cout << "<Очередь пуста>";
	}
	else
	{
		cout << "Очередь: ";
	}
     while (start != NULL)
     {
			  cout << (*start).val << " ";
			  start = (*start).next;
     }             
}
 
int menuQueue()
{
	setlocale(LC_ALL, "Rus");
	node_q *start = NULL, *end = NULL;
	int m = 0, val = 0;
	while (1)
	{
		do
		{
			system("CLS");
			print(start);
			cout << endl << endl;
			cout << "1. Добавить значение в очередь." << endl;
			cout << "2. Извлечь значение из очереди." << endl;
			cout << "0. Выход." << endl;
			cout << endl;
			cout << "Выберете пункт меню: ";
		} while (scanIntVal(m) || (m > 2) || (m < 0));

		switch (m)
		{
		case 1:
		{
			cout << endl;
			scanInt(val);
			add(val, &start, &end);
			break;
		}
		case 2:
		{
			if (start)
			{
				cout << endl << "Извлеченное значение: " << del(&start) << endl << endl;
				system("PAUSE");
			}
			else
			{
				cout << endl << "Очередь пуста!!" << endl << endl;
				system("PAUSE");
			}
			break;
		}
		default:
		{
			while (start)
			{
				node_q *temp = start->next;
				delete start;
				start = temp;
			}

			return 0;
		}
		}	// switch
	}	// while
}
