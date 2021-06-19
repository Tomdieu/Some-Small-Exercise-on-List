
#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int value;
	struct List *next;
}ListElement,*List;

typedef enum{false,true} bool;

List new()
{
	return NULL;
}

bool is_empty(List li)
{
	if(li == NULL)
		return true;
	return false;
}

List push(List li,int data)
{
	ListElement *e;

	e = calloc(sizeof(*e),1);

	if(e == NULL)
	{
		printf("Dynamic allocation memory error!\n");
		exit(EXIT_FAILURE);
	}

	e->value = data;
	e->next = NULL;

	if(li == NULL)
	{
		return e;
	}
	else
	{
		e->next = li;
		return e;
	}
}


List pop(List li)
{
	if(is_empty(li))
	{
		printf("Nothing to pop the list is empty\n");
		return NULL;
	}
	else
	{
		ListElement *e;
		e = li->next;
		free(li);
		return e; 
	}

}

void print(List li)
{
	if(is_empty(li))
	{
		printf("Nothing to display the list is empty!\n");
	}
	else
	{
		while(li != NULL)
		{
			printf("[%d] ",li->value);
			li = li->next;
		}
		printf("\n");
	}
}

List del(List li)
{
	while(li != NULL)
	{
		li = pop(li);
	}
	return li;
}

//Q1 a
List new_list(List li,int a,int b)
{
	li = push(li,a);
	li = push(li,b);

	return li;
}

//Q1 b
List new_n_list(List li,int size)
{
	int i,data;
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element : ",i);
		scanf("%d",&data);

		li = push(li,data);
	}
	return li;
}

//Q1 c
List new_n_list_with_condition(List li)
{
	int i,ele;
	i = 1;
	do
	{
		printf("Element %d =",i);b
		scanf("%d",&ele);
		if(ele == -1)
		{
			return li;
		}
		else
			li = push(li,ele);

	}while(1);//here which means while True
}
int main(int argc, char const *argv[])
{
	List e = new();
	e = new_n_list_with_condition(e);

	print(e);
	e=del(e);
	print(e);
	return 0;
}
