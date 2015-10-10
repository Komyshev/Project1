#include "io.h"

bool scanIntVal(int &a)
{
	if (!(cin >> a))
	{
		cin.clear();
		
		while (cin.get() != '\n')
		{

		}
		
		return 1;
	}

	return 0;
}

bool scanYesNo()
{
	char c;
	while (1)
	{
		c = _getch();
		if ( (c == 'Y') || (c == 'y') || (c == -83) || (c == -115) )
		{
			cout << 'Y' << endl << endl;
			return 1;
		}
		else if ( (c == 'N') || (c == 'n') || (c == -30) || (c == -110) )
		{
			cout << 'N' << endl << endl;
			return 0;
		}
	}	
}

int menuList()
{
	setlocale(LC_ALL, "Rus");

	node_list *begin = NULL;
	node_list *end = NULL;

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
		cout << "0. Выход." << endl << endl;


		cout << "Выберете пункт меню: ";
		while (scanIntVal(m) || (m < 0) || (m > 7))
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
		default:
		{
			while (begin)
			{
				node_list *temp = (*begin).next;
				delete begin;
				begin = temp;
			}
			return 0;
		}
		}
	}
}
