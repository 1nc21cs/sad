#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(char s)
{
 stack[++top]=s;
}
char pop()
{
return stack[top--];
}
int precd(char s)
{
switch(s)
{
case '^': return 4;
case '*':case '/': return 3;
case '+': case '-': return 2;
case '(': case ')': case '#':return 1;
 } }
void convertip(char infix[], char postfix[])
{
int i,j=0;
char symb;
push('#');
for(i=0;i<strlen(infix);i++)
{
symb=infix[i];
switch(symb)
{
case '(': push(symb);break;
case ')': while(stack[top]!='(')
postfix[j++]=pop();
pop();
break;
case '^': case '*': case '/': case '+': case '-': 
while(precd(symb)<=precd(stack[top]))
postfix[j++]=pop();
push(symb);
break;
 default: postfix[j++]=symb;
} }
while(stack[top]!='#')
 postfix[j++]=pop();
}
int main()
{
char infix[20],postfix[20];
printf("\n Enter infix expression");
gets(infix);
convertip(infix,postfix);
puts(postfix);
return 0;
}
