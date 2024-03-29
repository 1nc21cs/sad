#include<stdio.h>
#include<stdlib.h>

struct DLL
{
	int info;
	struct DLL *lptr,*rptr;
};
typedef struct DLL node;
node *start=NULL;
node *getnode_DLL()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("Enter the information\n");
	scanf("%d",&p->info);
	fflush(stdin);
	p->lptr=p->rptr=NULL;
	return p;
}

void insert_front()
{
	node *new1;
	new1=getnode_DLL();
	if (start==NULL)
	{
		start=new1;
		return;
	}
	else
	{
		start->lptr=new1;
		new1->rptr=start;
		start=new1;
	}
}

void insert_end(){
	node *new1,*temp;
	new1=getnode_DLL();
	if(start==NULL){
		start=new1;
		return;
	}
	else
	{
		temp=start;
		while(temp->rptr!=NULL){
			temp=temp->rptr;
		}
		temp->rptr=new1;
		new1->lptr=temp;
	}
}

void delete_last_node()
{
	node *temp;
	if(start==NULL)
	{
		printf("List is empty");
		return;
	}
	else
	{
		temp=start;
		while(temp->rptr!=NULL)
		{
			temp=temp->rptr;
		}
		printf("The delted info is %d\n",temp->info);
		(temp->lptr)->rptr=NULL;
		free(temp);
	}
}

void delete_first_node()
{
	node *temp;
	if(start==NULL)
	{
		printf("List is empty");
	}
	
	else if(start->lptr==NULL && start->rptr==NULL)
	{
		printf("The deleted info is %d\n",start->info);
		start=NULL;
		free(start);
	}
	else{
		temp=start;
		start=temp->rptr;
		start->lptr=temp->rptr=NULL;
		free(temp);
	}
}

void display()
     {
	int cnt=0;
	node  *temp;
	if(start==NULL)
	{
		printf("Empty list\n");
	}
	else
      {
	temp=start;
	printf("The details are:\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		cnt++;
		temp=temp->rptr;
	}
	}
	printf("\nthe total nodes in the list is %d\n",cnt);
}

int main()
{
 int ch;
 while(1)
 {
 printf("\n 1:insert_front\t 2:insert_end\t 3:delete_first_node\t 4:delete_last_node\t 5:display\n");
 printf("Enter the choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 	case 1:insert_front();
 	       break;
 	case 2:insert_end();
 	       break;
 	case 3:delete_first_node();
 	       break;
 	case 4:delete_last_node();
 	       break;
 	case 5:display();
 	       break;
 	default:exit(0);
        }
	 }	
	 return(0);
}
