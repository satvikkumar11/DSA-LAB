#include<stdio.h>
#include<stdlib.h>

typedef struct nodetype{
int info;
struct nodetype *next;	
}node;
void insertatbeg(node **start,int item)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
        ptr-> info=item;
        ptr->next=*start;
        *start=ptr;
}

void insertatend(node **start,int item)
{
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(*start==NULL)
	*start=ptr;
	else{
		last=*start;
		while(last->next!=NULL)
		last=last->next;
		
	}
	last->next=ptr;
}
void display(node *start)
{
	if(start==NULL)
	{
		printf("\nLinklist is empty");
		return;
	}
	while(start!=NULL)
	{
		printf("%d->",start->info);
		start=start->next;
	}
}
void deleteatbeg(node **start)
{
	node *ptr;
	if(*start==NULL)
	{
		printf("\n Linklist is empty");
		return;
	}
	ptr=*start;
	*start=ptr->next;
	printf("/ndelete value=%d",ptr->info);
	free(ptr);
}
void deleteatend(node **start)
{
	node *ptr,*last;
	if(*start==NULL)
	{
		printf("/nlinklist is empty");
		return;
	}
	if((*start)->next==NULL)
	{
		ptr=*start;
		*start=ptr->next;
	}
	else
	{
		last=*start;
		while(last->next!=NULL)
		last=last->next;
		ptr=last->next;
		last->next=NULL;
	}
	printf("\n deleted value=%d",ptr->info);
	free(ptr);
	
}
node *search(node*start,int key)
{
	while(start!=NULL && start->info!=key)
	start=start->next;
	return start;
}

void displayinrev(node *start)
{
	if(start->next!=NULL)
	displayinrev(start->next);
	printf("%d->",start->info);
}
void insertafterloc(node *start,int item,int after)
{
	node *ptr,*loc;
	loc = search(start,after);
	if(loc==NULL){
		printf("\n location not found");
		return;
	}
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=loc->next;
	loc->next=ptr;
}
void insertbefore(node **start,int item,int before)
{
	node *ptr,*loc,*temp;
	loc=*start;
	temp=NULL;
	while(loc!=NULL && loc->info!=before)
	{
		temp=loc;
		loc=loc->next;
	}
	if(loc==NULL)
	{
		printf("\n location not found");
		return;
	}
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	{
		if(loc==*start)
		{
			ptr->next=*start;
			*start=ptr;
		}
	}
	ptr->next=temp->next;
	temp->next=ptr;
}
void reverselinkedlist(node **start)
{
	node *pnode,*cnode,*nnode;
	pnode=NULL;
	cnode=*start;
	nnode=cnode->next;
	cnode->next=NULL;
	while(nnode!=NULL)
	{
		pnode=cnode;
		cnode=nnode;
		nnode=cnode->next;
		cnode->next=pnode;
		
	}
	*start=cnode;
}
int main()
{
	int item,choice;
	node *head;
	head=NULL;
	while(1)
	{
		printf("\n link list menu\n");
		printf("\n 1 insert at beg\n");
		printf("\n 2 at end\n");
		printf("\n 3 del at beg\n");
		printf("\n 4 del at end");
		printf("\n 5 dis in order\n");
		printf("\n 6 dis in rev\n");
		printf("\n 7 exit\n");
		printf("\n enter a choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n enter an item");
			        scanf("%d",&item);
			        insertatbeg(&head,item);
			        break;
			case 2:
				printf("\n enter an item");
			        scanf("%d",&item);
			        insertatend(&head,item);
			        break;
			case 3:
			        deleteatbeg(&head);
			        break;
			case 4:
			        deleteatend(&head);
			        break;
			case 5:
			        display(head);
			        break;
			case 6:
				displayinrev(head);
				break;
			default :
			      exit(1);	
		}
	}
}

