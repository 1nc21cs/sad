#include<stdio.h>
#include<stdlib.h>

int i,n;
struct employee
{
	int emp_numb,basic_sal;
	char emp_name[20];
	float all_allowance,gross_sal,IT,net_sal;
}e[10];

void read()
{
	printf("enter the number of employees\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the details of  employees\n");
		printf("emp_name=");
		scanf("%s",&e[i].emp_name);
		printf("employee number=");
		scanf("%d",&e[i].emp_numb);
		printf("basic_salary=");
		scanf("%d",&e[i].basic_sal);
    }
}

void calculate()
{
	for(i=0;i<n;i++)
	{
		e[i].all_allowance=1.23*e[i].basic_sal;
		e[i].gross_sal=e[i].basic_sal+e[i].all_allowance;
		e[i].IT=0.3*e[i].gross_sal;
		e[i].net_sal=e[i].gross_sal-e[i].IT;
	}
}

void display()
{
	printf("\n emp_name\t,emp_numb\t,basic_sal\t,all_allowance\t,gross_sal\t,IT\t,net_sal\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t,%d\t,%d\t,%f\t,%f\t,%f\t,%f\n",e[i].emp_name,e[i].emp_numb,e[i].basic_sal,e[i].all_allowance,e[i].gross_sal,e[i].IT,e[i].net_sal);
	
	}
}

void main()
{
	read();
	calculate();
	display();
}
