//QUEUE
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *ptr;
}*f=NULL,*r=NULL,*n;
void enQueue(int x)
{
	n=(struct node *)malloc(sizeof(struct node));
	if(!n)
	{
		printf("\nNode not created");
		return;
	}
	else if(r==NULL&&f==NULL)
	{
		n->ptr=NULL;
		n->data=x;
		f=n;
		r=n;
	}
	else
	{
		n->data=x;
		n->ptr=NULL;
		r->ptr=n;
		r=n;
	}
}
void deQueue()
{
	n=f;
	if(!n)
	{
		r=NULL;f=NULL;
		printf("\nQUEUE UNDERFLOW");
		return;
	}
	else
	{
		printf("\nDeleting %d",f->data);
		f=f->ptr;
		free(n);
	}
}
void display()
{
	n=f;
	if(!n)
	{
		r=NULL;f=NULL;
		printf("\nEmpty Queue");
		return;
	}
	printf("\nQUEUE\n");
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
	printf("\nMENU\n1.Insert\n2.Delete\n3.Display\n");
	do
	{
		printf("Choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter an element: ");
				scanf("%d",&c);
				enQueue(c);
				break;
			case 2: deQueue();
				break;
			case 3: display();
				break;
			default:printf("Invalid Option");
		}
		printf("Do you want to continue(1/0)? : ");
		scanf("%d",&c);
	}while(c);
	return 0;
}
