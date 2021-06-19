#include<stdio.h>
#include<stdlib.h>

typedef enum{false,true}Bool;

typedef struct DlistNode
{
	int value;
	struct DlistNode *back;
	struct DlistNode *next;
}DlistNode;

typedef struct Dlist
{
	int lenght;
	struct DlistNode *begin;
	struct DlistNode *end;	
}*Dlist;

Dlist new()
{
	return NULL;
}

Bool is_empty(Dlist li)
{
	if(li == NULL)
		return true;
	return false;
}

int list_lenght(Dlist li)
{
	if(is_empty(li))
		return 0;
	return li->lenght;
}

int First_element(Dlist li)
{
	if(is_empty(li))
		return -1;

	return li->begin->value;
}

int Last_element(Dlist li)
{
	if(is_empty(li))
		return -1;
	return li->begin->value;
}

int Search(Dlist li,int x)
{
	if(is_empty(li))
	{
		return -1;
	}
	else
	{
		DlistNode *temp = li->begin;
		while(temp != NULL)
		{
			if (temp->value == x)
			{
				return 1;
			}
			temp = temp->next;
		}
	}
	return 0;
}

Dlist PushBack(Dlist li,int x)
{
	DlistNode *e;
	e = malloc(sizeof(*e));
	if(e == NULL)
	{
		exit(0);
	}

	e->value = x;
	e->next = NULL;
	e->back = NULL;

	if(is_empty(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			exit(0);
		}
		li->lenght = 0;
		li->begin = e;
		li->end = e;
	}
	else
	{
		li->end->next = e; 
		e->back = li->end;
		li->end = e;
	}
	li->lenght ++;
	return li;
}
 
Dlist PushFront(Dlist li,int x)
{
	DlistNode *e;
	e = calloc(sizeof(*e),1);
	if(e == NULL)
	{
		exit(0);
	}

	e->value = x;
	e->next = NULL;
	e->back = NULL;

	if(is_empty(li))
	{
		li = malloc(sizeof(*li));
		if(li == NULL)
		{
			exit(0);
		}
		li->lenght = 0;
		li->begin = e;
		li->end = e;
	}
	else
	{
		li->begin->back = e; 
		e->back = li->begin;
		li->begin = e;
	}
	li->lenght ++;
	return li;
}

Dlist PopBack(Dlist li)
{
	if(is_empty(li))
	{
		return new();
	}
	if(li->begin = li->end)
	{
		free(li);
		li = NULL;
		return new();
	}

	DlistNode *temp = li->end;

	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;
	li->lenght --;
	return li;
}

Dlist PopFront (Dlist li)
{
	if(is_empty(li))
	{
		return new();
	}
	if(li->begin = li->end)
	{
		free(li);
		li = NULL;
		return new();
	}

	DlistNode *temp = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;

	free(temp);
	temp = NULL;
	li->lenght --;
	return li;INSERT
}

void display(Dlist li)
{
	if(is_empty(li))
	{
		printf("The List is empty\n");
		return;
	}
	DlistNode *temp = li->begin;
	while(temp != NULL)
	{
		printf("[%d]\n",temp->value);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	Dlist l = new();
	l = PushFront(l,2);
	l = PushBack(l,3);
	l = PushFront(l,1);
	display(l);
	display(l);
	l=PopFront(l);
	display(l);
	l=PopBack(l);
	display(l);
	printf("Lenght %d\n", l->lenght);
	return 0;
}
