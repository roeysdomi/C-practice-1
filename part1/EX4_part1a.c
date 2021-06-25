#include <stdlib.h>
#include <stdio.h>
#include "EX4_part1.h"
Node* head=NULL;
Node* mid=NULL;
int cntr=0;
int main()
{
	fflush(stdout);
	printf("%d\n",take(20));
	fflush(stdout);	
	printf("%d\n",take(10));	
	fflush(stdout);
	printf("%d\n",take(30));
	fflush(stdout);
	printf("%d\n",take(40));
	fflush(stdout);
	printf("%d\n",take(50));
	fflush(stdout);
	printf("%d\n",take(60));
	fflush(stdout);	
	return 0;
}


int take(int num)
{
	
	Node* node=newNode(num);
	add(node);
	return mid->data;	
}

void add(Node* node)
{	
	if(cntr==0)
	{
		head=node;
		mid=node;
		cntr=1;
		return;
	}
	node->next=head;
	head->prev=node;
	head=node;
	cntr++;
	if(cntr%2==0)
		mid=mid->prev;
}

Node* newNode(int data)
{
	Node* n=malloc(sizeof(Node));
	n->data=data;
	return n;
}




