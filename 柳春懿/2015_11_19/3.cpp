#include <stdio.h>

//找出区域之间权值最大的位置
int maxdata(int* data,int i,int j)
{
	int max = 0;//保存最大权值
	int maxi =0;//保存最大权值的位置
	for(int k=i+1;k<=i+j;k++)
	{
		if(max<data[k]+k)//权值函数
		{
			max = data[k]+k;
			maxi = k;
		}
	}
	return maxi;
}

//循环根据权值划分
int func(int *data,int len,int* outdata)
{
	int key = data[0];
	int keyi = 0;
	int outi = 0;
	int count = 0;
	outdata[outi] = key;
    while(1)
	{
		outi++;
		keyi = maxdata(data,keyi,key);
		key = data[keyi];
		outdata[outi] = key;
		count++;
		if(key > (len-keyi))
			break;
	}
	return count;
}

void main()
{
	int data[100];//输入数据
	int outdata[100];//输出数据
	FILE *fp = fopen("3.txt","r");
	int i = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%d",&data[i]);
		i++;
	}
	int count = func(data,i-1,outdata);
	outdata[++count] = data[i-1];//最后一个
	printf("%d\n",count);
	for(i=0;i<=count;i++)
	{
		if(count==i)
			printf("%d",outdata[i]);
		else
			printf("%d->",outdata[i]);
	}
}

