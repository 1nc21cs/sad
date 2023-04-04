#include<stdio.h>
int a[10],n;
void create()
{
	int i;
	printf("enter the the value of n");
	scanf("%d",&n);
	printf("entr the array of elements");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
void insert()
{
	int key,pos,i;

	printf("enter the key and position");
	scanf("%d%d",&key,&pos);
	for(i=n-1;i>=pos-1;i--)
	a[i+1]=a[i];
	a[i+1]=key;
	n++;
}

void display()
{
	int i;
	printf("the elements are\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}

void delete()
{
	int i,pos;
	printf("enter the position to be deleted elements");
	scanf("%d",&pos);
	for(i=pos-1;i<n;i++)
	a[i]=a[i+1];
	n--;
	
}
int main()
{
	int ch;
	while(1)
	{
		printf("enter the choise \n 1.create\n 2.insert\n 3.deleate\n 4.display\n 5.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			break;
			case 2:insert();
			break;
			case 3:delete();
			break;
			case 4:display();
			break;
			default :printf("error");
			break;
			
		}
	}
}
