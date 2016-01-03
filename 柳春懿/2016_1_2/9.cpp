#include <stdio.h>
int A[] = {5,4,3,2,1};
int B = 0;
int num = 0 ;
#define N 5
int sum = 0;

void printdata(int *data,int len)
{
	for(int i=0;i<len;i++)
		printf("%d ",data[i]);
	printf("\n");
	return;
}

//array�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�nlength������ĳ���
//�����������ǣ���������array���������
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        //�ӽ���λ��=2*�������λ�ã�+1
        nChild=2*i+1;
        //�õ��ӽ���нϴ�Ľ��
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
        //����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
			num++;
        }
        else break; //�����˳�ѭ��
    }
}
//�������㷨
int HeapSort(int array[],int length)
{
    int i;
    //�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //length/2-1�����һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
    for(i=length/2-1;i>=0;--i)
    {
		HeapAdjust(array,i,length);
	}
	int count = 1;
	if(array[0] == B)
	{
		return 1;
	}
    //�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for(i=length-1;i>0;--i)
    {
        //�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
        //��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
		num++;
        //������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
        HeapAdjust(array,0,i);
		count++;
		if(array[0] == B)
		{
			return count;
		}
		
    }
	return -1;
}






void swap(int *predata , int *data)
{
	int temp = *predata;
	*predata = *data;
	*data = temp;
}

int isempty(int *data,int key,int len)
{
	for(int i=key;i<len;i++)
	{
		if(data[i]==data[len])
			return false;
	}
	return true;
}

void func(int *data,int key,int len)//���������
{
	int i;
	int datatemp[10];
	if(key==len)
	{
		int rt;
		for(int j=0;j<N;j++)
		{
			FILE *fp = fopen("out.txt","a+");
			for(i=0;i<N;i++)
			{
				datatemp[i]=data[i];
				fprintf(fp,"%d",data[i]);
			}
			fprintf(fp,"\n");
			B++;
			rt = HeapSort(datatemp,N);
			fprintf(fp,"�������ݣ�%d  ��С��%d  ���Ӷ�%d\n",B,rt,num);
			fclose(fp);
			sum += num;
			num = 0;
		}
		B = 0;
	}
	
	for(i=key;i<len;i++)
	{	
		if(isempty(data,key,i))
		{
			swap(&data[key],&data[i]);
            func(data,key+1,len);
		    swap(&data[i],&data[key]);
		}
	}

}

long fact(int n) 
{ 
	long s; 
	if(n<=1)
		s=1; 
	else 
		s=n*fact(n-1); 
	return s; 
} 

void main()
{
	func(A,0,N);
	FILE *fp = fopen("out.txt","a+");
	fprintf(fp,"��ʱ�临�Ӷ�:%d,ƽ��ʱ�临�Ӷȣ�%f",sum,(float)sum/fact(N)/N);
	fclose(fp);
}
