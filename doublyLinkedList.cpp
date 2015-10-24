#include "doublyLinkedList.h"


/*    BRIEF: Добавление элементов в начало списка

		 IN:   val - значение

			 begin - указатель на начало списка

			   end - указатель на конец списка
					 (на случай, если список был пуст)
*/

void addBegin(int val, node_doublyLinkedList *&begin, node_doublyLinkedList *&end)
{
	node_doublyLinkedList *var = new node_doublyLinkedList;

	var->val = val;
	var->next = begin;

	if (begin)
	{
		begin->prev = var;
	}
	else
	{
		end = var;
	}

	begin = var;
}

/*    BRIEF: Добавление элементов в конец списка

		 IN:    val - значение

			  begin - указатель на начало списка
					  (на случай, если список был пуст)

				end - указатель на конец списка
*/

void addEnd(int val, node_doublyLinkedList *&begin, node_doublyLinkedList *&end)
{
	node_doublyLinkedList *var = new node_doublyLinkedList;

	var->val = val;

	if (end)
	{
		end->next = var;
		var->prev = end;
		end = var;
	}
	else
	{
		begin = var;
		end = var;
	}
}

/*	BRIEF: Добавить после элемента с заданным значением

	   IN: val - значение нового элемента

			n - значение элемента, после которого
				будет добавлен новый элемент


	  OUT:   1 - список пуст или заданное значение val в нем отсутствует

*/

int addAfter(int val, int n, node_doublyLinkedList *begin, node_doublyLinkedList *&end)
{
	if (!begin)
	{
		return 1;
	}

	while (begin->val != n)	         //  найдем адрес элемента 
	{                                //  с заданным значением n
		begin = begin->next;         //  либо адрес будет в begin,

		if (!begin)
		{
			return 1;                //  либо фукция вернет 1
		}
	}

	node_doublyLinkedList *temp = new node_doublyLinkedList;

	temp->val = val;
	temp->next = begin->next;
	temp->prev = begin;
	
	begin->next = temp;
	
	if (temp->next)
	{
		temp->next->prev = temp;
	}
	else
	{
		end = temp;
	}
	
	return 0;
}

/*	BRIEF: BRIEF: Добавить перед элементом с заданным значением

	   IN: val - значение нового элемента

			 n - значение элемента, перед которым
				 будет добавлен новый элемент


	  OUT:   1 - список пуст или заданное значение val в нем отсутствует

*/

int addBefore(int val, int n, node_doublyLinkedList *&begin, node_doublyLinkedList *end)
{
	if (!begin)
	{
		return 1;
	}

	node_doublyLinkedList *buf = begin;

	while (buf->val != n)
	{
		buf = buf->next;                     // в buf будет храниться адрес элемента со значением n
		
		if (!buf)
		{
			return 0;
		}
	}

	node_doublyLinkedList *temp = new node_doublyLinkedList;

	temp->val = val;
	temp->next = buf;
	temp->prev = buf->prev;

	buf->prev = temp;

	if (temp->prev)
	{
		temp->prev->next = temp;
	}
	else
	{
		begin = temp;
	}
	
	return 0;
}

/*	BRIEF: Удалить элемент с заданным значением

IN:	n - значение элемента, который
будет удален

OUT:  1 - список пуст или заданное значение val в нем отсутствует

*/

int erase(int n, node_doublyLinkedList *&begin, node_doublyLinkedList *&end)
{
	if (!begin)
	{
		return 1;
	}

	node_doublyLinkedList *buf = begin;

	while (buf->val != n)
	{
		buf = buf->next;                     // в buf будет храниться адрес элемента со значением n

		if (!buf)
		{
			return 1;
		}
	}

	if (buf->prev)
	{
		buf->prev->next = buf->next;
	}
	else
	{
		begin = buf->next;
	}


	if (buf->next)
	{
		buf->next->prev = buf->prev;
	}
	else
	{
		end = buf->prev;
	}
		
	delete buf;

	return 0;
}

/*	BRIEF: Сортировка (метод пузырька)

	  OUT:  1 - список пуст
*/

int sorting(node_doublyLinkedList *&begin, node_doublyLinkedList *&end)
{
	if (!begin)                                   //  если список пуст
	{
		return 1;
	}

	if (!(begin->next))                           //  если в списке
	{                                             //  всего один элемент
		return 1;
	}

	node_doublyLinkedList *endAssist = end;

	while (endAssist != begin)
	{
		node_doublyLinkedList *current = begin;
		while (current != endAssist)
		{
			if (current->val > current->next->val)
			{
				node_doublyLinkedList *first = current, *second = current->next;

				first->next = second->next;
				second->next = first;

				second->prev = first->prev;
				first->prev = second;



				if (second->prev)
				{
					second->prev->next = second;
				}
				else
				{
					begin = second;
				}

				if (first->next)
				{
					first->next->prev = first;
				}
				else
				{
					end = first;
				}

				if (second == endAssist)
				{
					endAssist = current;
				}

			}
			else
			{
				current = current->next;
			}
		}
		endAssist = endAssist->prev;
	}


	return 0;
	/*if (!begin)                                   //  если список пуст
	{
		return 1;
	}

	if (!(begin->next))                           //  если в списке
	{                                             //  всего один элемент
		return 1;
	}

	node_doublyLinkedList *end_assist = NULL;


	while (begin->next != end_assist)
	{
		if (begin->val > begin->next->val)
		{
			node_doublyLinkedList *temp = begin->next;

			begin->next = temp->next;
			temp->next = begin;

			if (!(begin->next))                       //  на случай, если в списке
			{                                         //  всего два элемента
				end = begin;
				begin = temp;
				return 0;
			}

			begin = temp;
		}

		node_doublyLinkedList *current = begin;

		while (current->next->next != end_assist)
		{
			if (current->next->val > current->next->next->val)
			{
				node_doublyLinkedList *temp1 = current->next, *temp2 = temp1->next;

				temp1->next = temp2->next;
				temp2->next = temp1;
				current->next = temp2;

				if (!(temp1->next))
				{
					end = temp1;
				}
			}
			current = current->next;
		}
		end_assist = current->next;
	}

	node_doublyLinkedList *temp = NULL, *current = begin;
	while (current)
	{
		current->prev = temp;
		temp = current;
		current = current->next;
	}

	return 0;*/
}

/* print, просто print.. */

void print(node_doublyLinkedList *begin)
{
	if (!begin)
	{
		cout << "<Cписок пуст>";
	}

	while (begin)
	{
		cout << (*begin).val << " ";
		begin = (*begin).next;
	}

	cout << endl << endl;
}

/* Вывод с конца */

void printConversely(node_doublyLinkedList *end)
{
	if (!end)
	{
		cout << "<Cписок пуст>";
	}

	while (end)
	{
		cout << (*end).val << " ";
		end = (*end).prev;
	}

	cout << endl << endl;
}

/*	BRIEF: Меню

OUT: 0 - когда был выбрал пункт выход
*/

int menuDoublyLinkedList()
{
	setlocale(LC_ALL, "Rus");

	node_doublyLinkedList *begin = NULL;
	node_doublyLinkedList *end = NULL;

	int m;
	while (1)
	{
		system("CLS");
		cout << "Работа со списком:\t\t\t";
		cout << endl << endl << endl;
		cout << "1. Добавить в начало." << endl << endl;
		cout << "2. Добавить в конец." << endl << endl;
		cout << "3. Добавить после элемента равного n." << endl << endl;
		cout << "4. Добавить перед элементом равным n." << endl << endl;
		cout << "5. Удалить элемент равный n." << endl << endl;
		cout << "6. Сортировка." << endl << endl;
		cout << "7. Вывести список." << endl << endl;
		cout << "8. Вывести список. (с конца и в обратном порядке)" << endl << endl;
		cout << "0. Выход." << endl << endl;


		cout << "Выберете пункт меню: ";
		while (scanIntVal(m) || (m < 0) || (m > 8))
		{
			cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
		}
		cout << endl;

		switch (m)
		{
		case 1:
		{
			int a;
			while (1)
			{
				cout << "Введите значение: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				addBegin(a, begin, end);
				cout << "Добавить еще значение? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 2:
		{
			int a;
			while (1)
			{
				cout << "Введите значение: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				addEnd(a, begin, end);
				cout << "Добавить еще значение? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 3:
		{
			int n, val;

			while (1)
			{
				cout << "Введите значение, которое нужно добавить: ";
				if (scanIntVal(val))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				cout << "Введите значение, после которого добавить: ";
				if (scanIntVal(n))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				if (addAfter(val, n, begin, end))
				{
					cout << "Список пуст или такого элемента в нем нет." << endl << endl;
					cout << "1. Добавить в начало." << endl << endl;
					cout << "2. Добавить в конец." << endl << endl;
					cout << "3. Попробовать еще раз." << endl << endl;
					cout << "0. Ничего не делать." << endl << endl;
					cout << "Выберете пункт меню: ";
					int q;
					while (scanIntVal(q) || (q < 0) || (q > 3))
					{
						cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
					}
					cout << endl;
					switch (q)
					{
					case 1:
					{
						addBegin(val, begin, end);
						break;
					}
					case 2:
					{
						addEnd(val, begin, end);
						break;
					}
					case 3:
					{
						continue;
						break;
					}
					default:
					{

					}
					}
					break;
				}
				else
				{
					break;
				}
			}
			break;
		}
		case 4:
		{
			int n, val;

			while (1)
			{
				cout << "Введите значение, которое нужно добавить: ";
				if (scanIntVal(val))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				cout << "Введите значение, перед которым добавить: ";
				if (scanIntVal(n))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}

				if (addBefore(val, n, begin, end))
				{
					cout << "Список пуст или такого элемента в нем нет." << endl << endl;
					cout << "1. Добавить в начало." << endl << endl;
					cout << "2. Добавить в конец." << endl << endl;
					cout << "3. Попробовать еще раз." << endl << endl;
					cout << "0. Ничего не делать." << endl << endl;
					cout << "Выберете пункт меню: ";
					int q;
					while (scanIntVal(q) || (q < 0) || (q > 3))
					{
						cout << "\nОшибка. Попробуйте еще раз.\n\nВыберете пункт меню: ";
					}
					cout << endl;
					switch (q)
					{
					case 1:
					{
						addBegin(val, begin, end);
						break;
					}
					case 2:
					{
						addEnd(val, begin, end);
						break;
					}
					case 3:
					{
						continue;
						break;
					}
					default:
					{

					}
					}
					break;
				}
				else
				{
					break;
				}
			}
			break;
		}
		case 5:
		{
			int a;
			while (1)
			{
				cout << "Введите значение, которое нужно удалить: ";
				if (scanIntVal(a))
				{
					cout << "\nОшибка. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if (erase(a, begin, end))
				{
					cout << "Такого значение в списке нет. Попробовать еще раз? (Y/N) -->";
					if (scanYesNo())
					{
						continue;
					}
					else
					{
						break;
					}
				}
				cout << "Элемент со значением " << a << " удален." << endl << endl;
				cout << "Удалить еще? (Y/N) -->";
				if (!scanYesNo())
				{
					break;
				}
			}
			break;
		}
		case 6:
		{
			if (!sorting(begin, end))
			{
				cout << "Отсортированный список:" << endl << endl;
			}
			print(begin);
			system("PAUSE");
			break;
		}
		case 7:
		{
			print(begin);
			system("PAUSE");
			break;
		}
		case 8:
		{
			printConversely(end);
			system("PAUSE");
			break;
		}
		default:
		{
			while (begin)
			{
				node_doublyLinkedList *temp = (*begin).next;
				delete begin;
				begin = temp;
			}
			return 0;
		}
		}
	}
}

int debug()
{
	node_doublyLinkedList *begin = NULL, *end = NULL;

	for (int i = 10; i > 0; i--)
	{
		addEnd(i, begin, end);
	}

	print(begin);

	sorting(begin, end);

	system("PAUSE");
	return 0;
}
