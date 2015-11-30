#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10000 

typedef struct 
{  
   int key;
}datatype; 

void  D_InsertSort(datatype R[],long  n)//直接排序
{ 
	long  i ,j;
    for(i=2;i<=n;i++)
	{  
		if(R[i].key<R[i-1].key)
		{
			R[0]=R[i];
			for(j=i-1;R[0].key<R[j].key;j--)
				R[j+1]=R[j];   
			R[j+1]=R[0]; 
		}  
	} 
} 

void Select_Sort(datatype R[],long  n)//简单选择排序
{ 
	long i,j;
	for(i=0;i<=n-1;i++)
	{
		long k=i;
		for(j=i+1;j<=n;j++)
		{
			if(R[k].key>R[j].key)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			R[0]=R[i];
			R[i]=R[k];
			R[k]=R[0];
		}
	}
} 

void Bubble_Sort(datatype R[],long n)//冒泡排序
{  
	long i,j,flag;  
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
			if(R[j].key>R[j+1].key)
			{
				R[0]=R[j];
				R[j]=R[j+1];
				R[j+1]=R[0];
				flag=1;
			}
			if(flag==0)
				break;
	}
} 

void HeapAdjust(datatype R[], long  s, long t)//堆调整
{ 
	datatype rc;
	long i,j; 
	rc=R[s];  
	i=s; 
	
	for(j=2*i;j<=t;j=2*j)
	{ 
		if(j<t&&R[j].key<R[j+1].key) 
			j=j+1;
		if(rc.key>R[j].key)
			break;  
		R[i]=R[j]; 
		i=j; 
	}  
	R[i]=rc;
} 

void HeapSort(datatype R[], long n)//堆排序
{  
	long i; 
	for(i=n/2;i>0;i--) 
		HeapAdjust(R,i,n);
	
	for(i=n;i>1;i--)
	{   
		R[0]=R[1]; 
		R[1]=R[i]; 
		R[i]=R[0];
		HeapAdjust(R,1,i-1); 
	} 
}
void Merge(datatype R[],datatype R1[], long s, long m, long t) 
{  
	long i ,j ,k; 
	i=s;j=m+1;k=s; 
	
	while(i<=m&&j<=t) 
	{  
		if(R[i].key<R1[j].key)
		{   
			R1[k++]=R[i++];  
		}
		else 
		{ 
			R1[k++]=R[j++]; 
		} 
	} 
	
	while(i<=m)
	{  
		R1[k++]=R[i++]; 
	} 
	
	while(j<=t)
	{  
		R1[k++]=R[j++]; 
	} 
	
	for(int p=s;p<=t;p++)
		R[p]=R1[p];
}

void MSort(datatype R[],datatype R1[], long s,long t)
{  
	long m;  
	if(s==t)
	{  
		R1[s]=R[s]; 
	}  
	else
	{ 
		m=(s+t)/2;
		MSort(R,R1,s,m);
		MSort(R,R1,m+1,t); 
		Merge(R1,R,s,m,t);  
	} 

} 

void MergeSort(datatype R[],datatype R1[],long n)//归并排序
{ 
	MSort(R,R1,1,n);
} 

long Partition(datatype R[], long low, long high) 
{ 
	R[0]=R[low]; 
	
	while(low<high) 
	{   
		while(low<high&&R[high].key>=R[0].key) 
		{   
			high--; 
		} 
		if(low<high) 
		{ 
			R[low]=R[high]; 
			low++; 
		}  
		
		while(low<high&&R[low].key<R[0].key)
		{ 
			low++; 
		} 
		if(low<high) 
		{   
			R[high]=R[low];
			high--;  
		} 
	} 
	R[low]=R[0]; 
	return low;

} 

void Quick_Sort(datatype R[],long s, long t)//快速排序
{   
	long i; 
	if(s<t) 
	{  
		i=Partition(R,s,t);
		Quick_Sort(R,s,i-1);
		Quick_Sort(R,i+1,t);
	} 
}

void prin(datatype R[], long n) 
{   
	long i; 
	int m;
	printf("请选择排序方法：\n");
	printf("1、直接排序\n");
	printf("2、简单选择排序\n");
	printf("3、冒泡排序\n");
	printf("4、堆排序\n");
	printf("5、归并排序\n");
	printf("6、快速排序\n");
	scanf("%d",&m);
	
	if(m==1){
	  D_InsertSort(R,n);//直接排序 
	}else if(m==2)
	{
      Select_Sort(R,n);//简单选择排序
	}else if(m==3){
		Bubble_Sort(R,n);//冒泡排序
	}else if(m==4){
		HeapSort(R,n); //堆排序
	}else if(m==5){
		datatype R2[MAXNUM]={0};
		MergeSort(R,R2,n);  
	}else if(m==6){
		Quick_Sort(R,0,n);//快速排序
	}
	
	printf("排序结果为：\n"); 
	for(i=1;i<=n;i++)
	{ 
		printf("%d ",R[i]);
	} 
	printf("\n"); 
} 

void sort() 
{     
	long i,n;
	datatype
		R[MAXNUM]={0};////定义结构数组
	printf("请输入元素个数:\n"); 
	scanf("%d",&n);  

	if(n>500000) 
	{   
		printf("超出范围重新输入\n");
		scanf("%d ",&n);
	} 
	printf("请输入%d个元素:\n",n);
	for(i=1;i<=n;i++)  
		scanf("%d",&R[i].key);  

	printf("排序前的元素顺序:\n");
	for(i=1;i<n+1;i++)  
	{  
		printf("%d ",R[i].key); 
	} 
	printf("\n"); 
	prin(R,n); 
} 

int main() 
{ 
	int n;
	do{
		sort(); 
		printf("请选择其他算法，不需要则请按0退出\n");
		scanf("%d",&n);
	}while(n!=0);

} 
