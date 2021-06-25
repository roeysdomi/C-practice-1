#include <stdlib.h>
#include <stdio.h>
#include "EX4_part1.h"

Node* head=NULL;
Node* mid=NULL;
int size=0;
int main()
{
	printf("%d\n",take2(20));
	fflush(stdout);
	printf("%d\n",take2(10));
	fflush(stdout);
	printf("%d\n",take2(30));
	fflush(stdout);
	printf("%d\n",take2(5));
	fflush(stdout);
	printf("%d\n",take2(40));
	fflush(stdout);
	
	return 0;
}

int take2(int num)
{
	Node* node=newNode(num);
	add(node);
	return mid->data;
}

void add(Node* node)
{	
	if(size==0)
	{		
		head=node;
		mid=node;
		mid->place=1;
		size=1;
		return;
	}
	Node* tmp=head;
	if(tmp->data > node->data)
	{
		node->next=head;
		head->prev=node;
		head=node;
		size++;
		updatePlaces(head);
		updateMid();
	}
	else
	{
		while(tmp->next!=NULL)
		{
			if(node->data > tmp->next->data)
				tmp=tmp->next;
			else
			{
				node->next=tmp->next;
				node->prev=tmp;
				tmp->next->prev=node;
				tmp->next=node;
				
				break;
			}
		}
		if(tmp->next==NULL)
		{
			tmp->next=node;
			node->prev=tmp;
			
		}
		size++;
		node->place=tmp->place+1;
		updatePlaces(tmp);
		updateMid();
	}
}

void updatePlaces(Node* tmp)
{
	if(tmp!=head)
		tmp=tmp->next->next;
	while(tmp!=NULL)
	{
		tmp->place++;
		tmp=tmp->next;
	}
}

void updateMid()
{
	if(size%2==0 && mid->place > size/2)
		mid=mid->prev;
	if(size%2==1 && mid->place < size/2+1)
		mid=mid->next;	
}





Node* newNode(int data)
{
	Node* n=malloc(sizeof(Node));
	n->data=data;
	n->place=0;
	return n;
}

