#include<stdio.h>
#include<stdlib.h>
int L[100],max=5;
void display()
{
int i;
printf("\n Hash table contents are ");
printf("\n Index\tdata\n");
for(i=0;i<max;i++)
printf("\n%d\t%d\n",i,L[i]);
}
void linear_probe(int key,int num)
{
int i;
if(L[key]==-1)
L[key]=num;
else
{
printf("\n Collision detected");
i=(key+1)%max;
while(i!=key)
{
if(L[i]==-1)
{
L[i]=num;
printf("\n Collision resolved through linear probe");
return;
}
i=(i+1)%max;
}
printf("\n Hash table is full");
display();
}
}
int main()
{
int i,num,key,input;
for(i=0;i<max;i++)
L[i]=-1;
do
{
printf("\n Enter the number");
scanf("%d",&num);
key=num%max;
linear_probe(key,num);
printf("\n Enter 1 to continue");
scanf("%d",&input);
}while(input==1);
display();
return 0;
}
