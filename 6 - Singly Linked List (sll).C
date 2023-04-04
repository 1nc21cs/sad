#include<stdio.h>
#include<stdlib.h>
struct SLL
{
	char usn[10];
	//char name[30];
	//char branch[4];
	//int sem;
	//long int phno;
	struct SLL *next;
};
typedef struct SLL node;
node *start=NULL;

node *getnode()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("\n Enter USN");
	scanf("%s",p->usn);
	fflush(stdin);
	p->next=NULL;
	return p;	
}

void insert_front()
{
	node *n1;
	n1=getnode();
	n1->next=start;
	start=n1;
	
}


void delete_front()
{
	node *temp;
	if(start==NULL)
{
		printf("\n Empty list");
		return;
}
		temp=start;
		printf("%s info is deleted\n",temp->usn);
		start=temp->next;
		free(temp);
}


void insert_end()
{
	node *n1,*temp;
	n1=getnode();
	if(start==NULL)
{
		start=n1;
		return;
}
	temp=start;
	while(temp-> next!=NULL)
	          temp=temp->next;	
		
	temp-> next=n1;
}


void delete_end()
{
	node *temp, *prev;
	if(start==NULL)
{
		printf("\n Empty list");
		return;
}
	if(start-> next ==NULL)
	{
		printf("\n%s student details is deleted",start->usn);
		free(start);
		start=NULL; return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	printf("\nThe deleted node is \t%s\n",temp->usn);
	free(temp);
}
	
	
void display()
{
	int cnt=0;
	node *temp;
	if(start==NULL)
{
		printf("\n Empty list");
		return;
}
	temp=start;
	printf("\n The details are\n");
	while(temp != NULL)
	{
		printf("\n%s\t", temp->usn);
		cnt++;
		temp=temp->next;
	}
	printf("\n Number of nodes is %d",cnt);
}


int main()
{
	int n, m, i;
	
	while(1)
	{
printf("\n Enter 1:insert_front\n 2:insert_end\n 3:delete_front\n 4:delete_end\n 5:display\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:printf("\n Enter n");
				   scanf("%d",&n);
				   for(i=0;i<n;i++)
				  	 insert_front();
			break;
			case 2: insert_end();
			break;
			case 3: delete_front();
			break;
			case 4: delete_end();
			break;
			case 5: display();
			break;
			default:exit(0);
		}
	}
	return 0;
}
