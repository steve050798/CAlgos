//STACK
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *ptr;
}*top=NULL,*n;
void push(int x)
{
	n=(struct node *)malloc(sizeof(struct node));
	if(!n)
	{
		printf("\nNode not created");
		return;
	}
	else
	{
		n->data=x;
		n->ptr=top;
		top=n;
	}
}
void pop()
{
	n=top;
	if(!n)
	{
		printf("\nSTACK UNDERFLOW");
		return;
	}
	else
	{
		printf("Deleting %d\n",top->data);
		top=top->ptr;
		free(n);
	}
}
void display()
{
	n=top;
	if(!n)
	{
		printf("\nEmpty Stack");
		return;
	}
	printf("\nSTACK\n");
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n=n->ptr;
	}
	printf("\n");
}
int main()
{
    int c;
    printf("\nMENU\n1.Push\n2.Pop\n3.Display\n");

	do
	{
		printf("Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter an element: ");
				scanf("%d",&c);
				push(c);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default:printf("Invalid Option");
		}
		printf("Do you want to continue(1/0)? : ");
		scanf("%d",&c);
	}while(c==1);
	return 0;
}
