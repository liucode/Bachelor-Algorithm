#include <stdio.h>

//�ҳ�����֮��Ȩֵ����λ��
int maxdata(int* data,int i,int j)
{
	int max = 0;//�������Ȩֵ
	int maxi =0;//�������Ȩֵ��λ��
	for(int k=i+1;k<=i+j;k++)
	{
		if(max<data[k]+k)//Ȩֵ����
		{
			max = data[k]+k;
			maxi = k;
		}
	}
	return maxi;
}

//ѭ������Ȩֵ����
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
	int data[100];//��������
	int outdata[100];//�������
	FILE *fp = fopen("3.txt","r");
	int i = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%d",&data[i]);
		i++;
	}
	int count = func(data,i-1,outdata);
	outdata[++count] = data[i-1];//���һ��
	printf("%d\n",count);
	for(i=0;i<=count;i++)
	{
		if(count==i)
			printf("%d",outdata[i]);
		else
			printf("%d->",outdata[i]);
	}
}

