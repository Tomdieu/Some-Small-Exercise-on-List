#include<stdio.h>
#include<stdlib.h>


typedef struct List
{
	int data ;
	struct List *next;
}*List;

List new()
{
	return NULL;
}

int is_empty(List li)
{
	if(li == NULL)
		return 1;
	return 0;
}

List insert(List li,int x)
{
	List e;
	e = malloc(sizeof(*e));
	if(e == NULL)
		exit(1);
	e->data = x;
	e->next = NULL;
	if(is_empty(li))
	{
		return e;
	}
	else
	{
		e->next = li;
		return e;
	}
}

List pop(List li)//this function here is the function that remove the first element from the list
{
	if(is_empty(li))
		return NULL;
	List temp = li;
	li = temp->next;
	free(temp);
	temp = NULL;
	return li;
}

List clear(List li)
{
	if(is_empty(li))
		return NULL;
	else
		while(! is_empty(li))
			li = pop(li);
	return li;
}

void display(List li)
{
	if(is_empty(li))
		printf("The list is empty\n");
	while(li != NULL)
	{
		printf("[%d] ",li->data);
		li = li->next;
	}
	printf("\n");
}

List Delete_all_occurence(List li,int x)
{
	List temp = new();
	if(is_empty(li))
		return NULL;
	while(li != NULL)
	{
		if(li->data != x)
		{
			temp = insert(temp,li->data);
		}
		li = li->next;
	}
	return temp;
}

List delete_first_occurence(List li,int x)
{
	/*
	*	so what i will do here is that i will consider a list L having 
		elements : 1,2,1,2
		now if i want to remove the first occurence of 1
		i will use a variable count to check if we had seen the first occurence
		of 1 when traversing the list if yes we set i to 1 and pass
		so that even if we encounter another one again if (L->data = 1 and count = 1) of L->data != 1
		we are going to add it to our temporal list temp and if 
	*/
	int count = 0;
	List temp;
	while(li != NULL)
	{
		if(li->data == x && count == 0)
		{
			count = 1;
		}
		else //if((li->data == x && count ==1) || (li->data != x))
		{
			temp = insert(temp,li->data);
		}
		li = li->next;

	} 
	return temp;
}

int main(int argc, char const *argv[])
{
	List e = new();
	int a[]={1,2,2,2,4,1,2,1,3};
	int i;
	for(i=0;i<sizeof(a)/sizeof(*a);i++)
	{
		e = insert(e,a[i]);
	}
	display(e);
	printf("After deleleting all the occurence of %d\n",1);
	e = Delete_all_occurence(e,1);
	display(e);
	e = delete_first_occurence(e,2);
	display(e);
	e = clear(e);
	display(e);
	return 0;
}
