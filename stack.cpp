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
	if (!top)
	{
		cout << "<Стек пуст>" << endl << endl;
	}
	else
	{
		cout << "Стек: ";
	}
	while (top != NULL)
	{
		cout << top->val << " ";
		top = top->prev;
	}
}

int menuStack()
{
	setlocale(LC_ALL, "Rus");
	node_s *top = NULL;
	int m = 0, val = 0;
	while (1)
	{
		do
		{
			system("CLS");
			print(top);
			cout << endl << endl;
			cout << "1. Добавить значение в стек." << endl;
			cout << "2. Извлечь значение из стека." << endl;
			cout << "0. Выход." << endl;
			cout << endl;
			cout << "Выберете пункт меню: ";
		} while (scanIntVal(m) || (m > 2) || (m < 0));

		switch (m)
		{
			case 1:
			{
				scanInt(val);
				push(val, &top);
				break;
			}
			case 2:
			{
				if (top)
				{
					cout << endl << "Извлеченное значение: " << pop(&top);
					system("PAUSE");
				}
				else
				{
					cout << endl << "Стек пуст!!" << endl << endl;
					system("PAUSE");
				}
				break;
			}
			default:
			{
				while (top)
				{
					node_s *temp = top->prev;
					delete top;
					top = temp;
				}

				return 0;
			}
		}	// switch
	}	// while
}
