#include<stdio.h>
#include<stdlib.h>
#define max 4
int a[10],top=-1;
void push(int m)
{
if(top==max-1)
printf("\n Stack overflow");
 else
a[++top]=m;
}
int pop()
{
if(top==-1)
printf("\n Stack underflow");
else
return a[top--];
}
void display()
{
int i;
if(top==-1)
printf("\n Stack is empty");
else
{
printf("\n The elements are");
for(i=top;i>=0;i--)
printf("%d\t",a[i]);
}
}
void palin()
{
int n,num,rem=0,flag=1;
printf("\n Enter n");
scanf("%d",&n);
num=n;
while(n!=0)
{
rem=n%10;
push(rem);
n=n/10;
}
while(num!=0)
{
if(num%10!=pop())
{
flag=0;
break;
}
num=n/10;
}
if(flag==0)
printf("\n It is not a palindrome");
else
printf("\n It is a palindrome");
}
int main()
{
int c,m;
while(1)
{ printf("\n 1 push\n 2 pop\n 3 display\n 4 palindrome");
 scanf("%d",&c);
 switch(c)
 {
case 1: printf("\n Enter an element\t");
 scanf("%d",&m);
 push(m);
 break;
case 2: printf("\n The popped elementis %d", pop());
 break;
case 3: display();break;
case 4:palin();break;
default:exit(0);break;
}
 }
return 0;
}
