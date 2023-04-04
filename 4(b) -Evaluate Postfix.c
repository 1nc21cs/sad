#include<stdio.h>
#include<string.h>
#include<ctype.h>
float stack[20];
int top=-1;

void push(char symb)
{
	stack[++top]=symb;
}

float pop()
{
	return stack[top--];
}

float eval_postfix(char postfix[])
{
	int i;
	float op1,op2;
	char symb;
	for(i=0;i<strlen(postfix);i++)
	{
	 symb=postfix[i];
	 if(isdigit(symb))
	 {
	    push(symb-'0');
	}
	 else
	 {
	 	op2=pop();op1=pop();
	 	switch(symb)
	 	{
	 		case '+':push(op1+op2);break;
	 		case '-':push(op1-op2);break;
	 		case '*':push(op1*op2);break;
	 		case '/':push(op1/op2);break;
		 }
		 }	
	}
	return pop();
}

int main()
{
	float val;
	char postfix[20];
	printf("Enter valid postfix expression\n");
	gets(postfix);
	val=eval_postfix(postfix);
	printf("\n Result of postfix expression %s=%f",postfix,val);
	return 0;
}
