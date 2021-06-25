#include <stdbool.h>
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "EX4_part2.h"
Node* head;
int main()
{
	int size = 3;
	char** c=calloc(size,sizeof(char*));
	
	c[0]="c{{g([j])}";
	c[1]="c{g([j])}()";
	c[2]="c{g}()}";
	printf("answer is %d \n",isStringBalanced(c,size));
	fflush(stdout);
	return 0;
}




bool isStringBalanced(char** sentence, int size)
{
	head=newNode('\0');	
	for(int i=0;i<size;i++)
	{
		size_t sen_size=strlen(*(sentence+i));
		for(int j=0;j<sen_size;j++)
		{
			char letter=*(*(sentence+i)+j);
			if(letter=='{' || letter=='(' || letter=='[') 
				push(letter);
			else if(letter=='}' || letter==']' || letter==')')
				if(!pop(letter))
					return false;
		}
	}
	
	if(head->letter=='\0')
		return true;
	return false;
}

Node* newNode(char letter)
{
	Node* n=malloc(sizeof(Node));
	n->letter=letter;
	return n;
}

void add(Node* node)
{	
	node->next=head;
	head=node;
}

void push(char letter)
{
	Node* n=newNode(letter);
	add(n);
}

bool pop(char letter)
{
	Node* tmp;
	if(letter=='}')
	{
		if(head->letter=='{')
		{
			tmp=head;
			head=head->next;
			free(tmp);
			return true;
		}
	}
	else if(letter==')')
	{
		if(head->letter=='(')
		{
			tmp=head;
			head=head->next;
			free(tmp);
			return true;
		}
	}
	else if(letter==']')
	{
		if(head->letter=='[')
		{
			tmp=head;
			head=head->next;
			free(tmp);
			return true;
		}
	}
	return false;
}




