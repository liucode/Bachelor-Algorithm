#include <stdio.h>
#include <math.h>
int total=1;
void one(int m,int n)
{
	int sum=1;
	while(m>0)
	{
		sum = sum*n;
		if(sum>1000)
			sum = sum%1000;
		m--;
	}
	printf("%d\n",sum);
}

void two(int m,int n,int total)
{
	int i =0;
	int sum = n;
	if (m<=1)
	{
		
		printf("%d\n",(total*n)%1000);
		return;
	}
	while(true)
	{
		sum *= sum;
		if(sum>1000)
			sum %= 1000;
		if(i==0)
			m -= 2;
		else
			m -= pow(2,i);
		i++;
		if(m <= pow(2,i))
			break;
	}
    two(m,n,(sum*total)%1000);
}

void f(int n,int* data,int i) 
{ 
	int sum =1;
	if(n) 
		f(n/2,data,++i); 
	else return; 
    if(n%2 == 1)
	{
		sum *= data[i-1];
		sum %=1000;
	}
	total = (sum*total)%1000;
} 

void three(int m,int n)
{
    int data[100];
	int i = 1;
	data[0] = n;
	for(;i<=sqrt(n);i++)
	{
		data[i] = (data[i-1]*data[i-1])%1000;
	}
	f(m,data,0);
	printf("%d",total);
}


void main()
{
	int n,m;
	scanf("%d,%d",&n,&m);
	one(m,n);
	two(m,n,1);
	three(m,n);
}


