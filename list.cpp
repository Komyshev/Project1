#include "list.h"


/*    BRIEF: Добавление элементов в начало списка

         IN:   val - значение

               begin - указатель на начало списка

               end - указатель на конец списка
                     (на случай, если список был пуст)	
*/

void addBegin(int val, node_list *&begin, node_list *&end)
{
	node_list *var = new node_list;
	
	var->val = val;
	var->next = begin;
	
	begin = var;
	
	if (!end) 
	{
		end = begin;             //  В случае, когда список был пуст,
    }                            //  значение end должно быть изменено
}

/*    BRIEF: Добавление элементов в конец списка

         IN:    val - значение

              begin - указатель на начало списка
                      (на случай, если список был пуст)

                end - указатель на конец списка
*/

void addEnd(int val, node_list *&begin, node_list *&end)
{
	node_list *var = new node_list;
	
	var->val = val;
	var->next = NULL;
	
    if (end) 
	{
		end->next = var;           
	}
    else 
	{									//  В случае, когда список был пуст,
			begin = var;                //  значение begin должно быть изменено
	}
    
	end = var;
}

/*	BRIEF: Добавить после элемента с заданным значением

	   IN: val - значение нового элемента
	   
	   		 n - значение элемента, после которого 
			   	 будет добавлен новый элемент
			 
			   	 
	  OUT:   1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int addAfter(int val, int n, node_list *begin, node_list *&end)
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
	
	node_list *temp = new node_list;
	
	temp->val = val;
	temp->next = begin->next;
	
	begin->next = temp;
	                                  
									  
	if (begin == end)                 //  если новый элемент был добален
	{                                 //  после последнего, то значение
		end = temp;                   //  end должно быть изменено на адрес 
	}                                 //  нового элемента
	                                  
	return 0;
}

/*	BRIEF: BRIEF: Добавить перед элементом с заданным значением

	   IN: val - значение нового элемента
	   
	   		 n - значение элемента, перед которым
			   	 будет добавлен новый элемент
			 
			   	 
	  OUT:   1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int addBefore(int val, int n, node_list *&begin, node_list *end)
{
	if (!begin)
	{
		return 1;
	}
	
	if (begin->val == n)                   //  если элемент со значением n
	{                                      //  есть первый элемент в списке,
		node_list *temp = new node_list;
		
		temp->val = val;
		temp->next = begin;                
		                                   //  теперь первым будет элемент 
		begin = temp;                      //  с адресом temp
		
		return 0;
	}
	else
	{
		node_list *buf = begin;	            
		                                   
		while ((buf->next)->val != n)	   //  найдем адрес элемента, 
		{                                  //  за которым следует элемент
			buf = buf->next;               //  со значением n
			if (!buf->next)                //  либо адрес будет в buf,
			{                              
				return 1;	               //  либо функция вернет 1
			} 
		}                                  
		                                   
		node_list *temp = new node_list;
		
		temp->val = val;
		temp->next = buf->next;
		
		buf->next = temp;
		
		return 0;
	}	
}

/*	BRIEF: Удалить элемент с заданным значением

	   IN:	n - значение элемента, который
		    	будет удален			 
			   	 
	  OUT:  1 - список пуст или заданное значение val в нем отсутствует
		 	
*/

int erase(int n, node_list *&begin, node_list *&end)
{
	if (!begin)
	{
		return 1;
	}
	
	if (begin->val == n)                   //  если элемент со значением n
	{                                      //  есть первый элемент в списке,
		node_list *temp = begin->next;	
		
		delete (begin);
		
		begin = temp;
		
		if (!begin)
		{
			end = begin;
		}
		
		return 0;
	}
	else
	{
		node_list *buf = begin;	            
		                                   
		while ((buf->next)->val != n)	   //  найдем адрес элемента, 
		{                                  //  за которым следует элемент
			buf = buf->next;               //  со значением n
			if (!buf->next)                //  либо адрес будет в buf,
			{
				return 1;	               //  либо функция вернет 1
			}
			
		}                                  
		                                   
		node_list *temp = buf->next;
		
		buf->next = temp->next;
		
		delete (temp);
		
		if (!buf->next) 
		{
			end = buf;                     //  если удалили последний..
		}
		
		return 0;
	}	
}

/*	BRIEF: Сортировка

	  OUT:  1 - список пуст
*/

int sorting(node_list *&begin, node_list *&end)
{
	if (!begin)                                   //  если список пуст
	{
		return 1;
	}

	if (!(begin->next))                           //  если в списке
	{                                             //  всего один элемент
		return 1;
	}

	node_list *end_assist = NULL;


	while (begin->next != end_assist)
	{
		if (begin->val > begin->next->val)
		{
			node_list *temp = begin->next;

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

		node_list *current = begin;

		while (current->next->next != end_assist)
		{
			if (current->next->val > current->next->next->val)
			{
				node_list *temp1 = current->next, *temp2 = temp1->next;

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
	return 0;
}

/* print, просто print.. */

void print(node_list *begin)
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
