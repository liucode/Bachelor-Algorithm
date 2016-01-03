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

//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
//本函数功能是：根据数组array构建大根堆
void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        //子结点的位置=2*（父结点位置）+1
        nChild=2*i+1;
        //得到子结点中较大的结点
        if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(array[i]<array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
			num++;
        }
        else break; //否则退出循环
    }
}
//堆排序算法
int HeapSort(int array[],int length)
{
    int i;
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //length/2-1是最后一个非叶节点，此处"/"为整除
    for(i=length/2-1;i>=0;--i)
    {
		HeapAdjust(array,i,length);
	}
	int count = 1;
	if(array[0] == B)
	{
		return 1;
	}
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(i=length-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
		num++;
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
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

void func(int *data,int key,int len)//迭代的求解
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
			fprintf(fp,"测试数据：%d  大小：%d  复杂度%d\n",B,rt,num);
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
	fprintf(fp,"总时间复杂度:%d,平均时间复杂度：%f",sum,(float)sum/fact(N)/N);
	fclose(fp);
}
