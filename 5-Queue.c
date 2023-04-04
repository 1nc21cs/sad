#include<stdio.h>
#include<stdlib.h>
#define size 7
char cq[size];
int r=-1,f=0,cnt=0;

void cq_insert()
{
	if(cnt==size)
	{
		printf("Cq is full\n");
		return;
	}
	printf("Enter the Rainbow color\n");
	r=(r+1)%size;
	scanf("%s",&cq[r]);
	
	cnt++;
}

void del()
{
	if(cnt==0)
	{
		printf("Cq is empty\n");
		return;
	}
	printf("The deleted Rainbow color is %c",cq[f]);
	f=(f+1)%size;
	cnt--;
}

void cq_display()
{
	int i,k=f;
	if(cnt==0)
	{
		printf("Cq is empty\n");
		return;
	}
	printf("\n Cq Rainbow color are\n");
	for(i=0;i<cnt;i++)
	{
		printf("%c",cq[k]);
		k=(k+1)%size;
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Cq_insert\n 2.cq_delete\n 3.cq_display\n 4.exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:cq_insert();break;
			case 2:del();break;
			case 3:cq_display();break;
			case 4:exit(0);break;
			default:printf("Invalid input");
		}
	}
	return 0;
}
