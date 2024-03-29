#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct sll
{
	int info;
	struct sll *rptr;
};
typedef struct sll node;
node *start=NULL,*s1=NULL,*s2=NULL;
node *getnode()
{
	node *n1;
	n1=(node*)malloc(sizeof(node));
	n1->rptr=NULL;
	printf("\nenter the info\n");
	scanf("%d",&n1->info);
	return n1; 
}
void insert_begin()
{
	node *n1;
	n1=getnode();
	if(start==NULL)
	{
		start=n1;
		return;
	}
	n1->rptr=start;
	start=n1;
}
void display()
{
	node *temp=start;
	int cnt=0;
	if(start==NULL)
	{
		printf("the list is empty\n");
		return;
	}
	printf("\n the elements in the sll are .....\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->rptr;
		cnt++;
	}
	printf("the total number of nodes in sll :%d ",cnt);
}
void sort_list()
{
	node *current=start,*index;
	int temp;
	while(current!=NULL)
	{
		index=current->rptr;
		while(index!=NULL)
		{
			if(current->info>index->info)
			{
				temp=current->info;
				current->info=index->info;
				index->info=temp;
			}
			index=index->rptr;
		}
		current=current->rptr;
	}
	display();
}
void concat(node *s1,node*s2)
{
	node *temp=s1;
	while(temp->rptr!=NULL)
	temp=temp->rptr;
	temp->rptr=s2;
}
void reverse()
{
	node *temp,*prev=NULL;
	while(start!=NULL)
	{
		temp=start;
		start=start->rptr;
		temp->rptr=prev;
		prev=temp;	
	}
	start=temp;
	display();
}
int main()
{
	node *temp,*n1,*n2;
	int i,n,m,ch;
	while(1)
	{
		printf("\n enter the choice\n");
		printf("1.insert\t2.display\t3.sort\t4.concate\t5.reverse\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the no of elements to be insert\n");
			        scanf("%d",&n);
			        for(i=0;i<n;i++)
			        {
			        	insert_begin();
					}
			       break;
			case 2:display();break;
			case 3:sort_list();break;
			case 4:printf("enter no.of elements in list1\n");
			       scanf("%d",&n);
			       printf("enter the list1 elements\n");
			       for(i=0;i<n;i++)
			       {
			       	n1=getnode();
			       	n1->rptr=s1;
			       	s1=n1;
				   }
				   printf("enter no.of elements in list2\n");
			       scanf("%d",&m);
			       printf("enter the list2 elements\n");
			       for(i=0;i<n;i++)
			       {
			       	n2=getnode();
			       	n2->rptr=s2;
			       	s2=n2;
				   }
				   concat(s1,s2);
				   temp=s1;
				   while(temp!=NULL)
				   {
				   	printf("%d\t",temp->info);
				   	temp=temp->rptr;
				   }
			       break;
			case 5:reverse();break;
			default:printf("enter the correct choice");break;
		}
	}
	return 0;
}
