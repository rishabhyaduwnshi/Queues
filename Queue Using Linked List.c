#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(struct Node *temp,int x)
{
	struct Node *last = NULL,*p;
	if(temp == NULL)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = x;
		temp->next = NULL;
		front = temp;
		rear = temp;
	}
	
	else
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			p->data = x;
			p->next = NULL;
			rear->next = p;
			rear = p;
		}
	
	
}

int dequeue(struct Node *temp)
{
	int x = -1;
	struct Node *p = NULL;
	if(temp == NULL)
	{
		printf("Queue is Empty ");
		
	}
	else
	{
		p = front;
		front = front->next;
		x = p->data;
		free(p);
	}
}


void displayQueue(struct Node *temp)
{
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main()
{
	int n,i,data;
	printf("Enter the number of elemnts to enqueue : ");
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		enqueue(rear,data);
	}
	printf("Elements present in Queue are : ");
	displayQueue(front);
	
	printf("\n\nEnter the number of elemnts to dequeue : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	dequeue(front);
	
	printf("\nNow elements present in Queue are : ");
	displayQueue(front);
}
