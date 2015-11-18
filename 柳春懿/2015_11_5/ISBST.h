/***
  1.����һ�������ԣ���(a[0],b[0]),(a[1],b[1])��(a[n-1],b[n-1]?��������aֵ��bֵ�ֱ��ظ�(����i��=j����a[i]��=a[j]��b[i]��=b[j])������һ��n���Ķ��������������������Է��䵽��������ϡ��������е�������������������
   (1)���н���aֵ��������������˳�򣬼�left��a<root��a&&root��a<right��a��
   (2)���н��bֵ�������ѵ�˳�򣬼�root��b>left��b&&root��b>right��b��
              (2016У�а���Ͱ�C++����ʦ������Ŀ)
***/

#include <stdio.h>
#include <malloc.h>

#define MAX 10000



typedef struct BiTreeNode 
{
    int data;
	struct BiTreeNode  *lchild;
	struct BiTreeNode  *rchild;
} BiNode;



//print Bitree
void Bitreeprint(BiNode *p);
//insert data in Bitree
BiNode* Bitreeinsert(int data,BiNode *root);


void CreateBitree(BiNode *root);
 
void swap(float &src,float &pat)//������������
{
    float temp;
	temp=src;
	src=pat;
	pat=temp;

}
