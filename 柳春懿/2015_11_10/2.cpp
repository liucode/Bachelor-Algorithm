#include "stdio.h"
void fun(int *data,int len)
{
	int i = 0;
	int count = 1;
	int maxcount = 1;
	int maxi = 0;
	for(;i < len;i++)
	{
		while(data[i+1] - i - 1==data[i] - i)
		{
			count++;
			i++;
		}
		if(count > maxcount)
		{
			maxcount = count;
			maxi = i;
		}
		count = 1;
	}
	for( i = maxi-maxcount+1;i<=maxi;i++)
	{
		printf("%d ",data[i]);
	}
}
void main()
{
	int data[100];
	FILE *fp = fopen("2.txt","r");
	int i = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%d",&data[i]);
		i++;
	}
	int datalen = i;
	fun(data,datalen);
	
}
