#include "ISBST.h"


void HeapAdjust(float *data,int s,int m)
{
     float rc;
	 rc=data[s];
	 for (int j=2*s;j<m;j*=2)
	 {
		 if (j<m&&data[j]<data[j+1])
		 {
			 j++;
		 }
		 if(data[j]<rc)
		 {
			 break;
		 }
		 data[s]=data[j];
		 s=j;
	 }
	 data[s]=rc;
}

void Heapsort(float *data,int len)
{
    for (int i=len/2-1;i>=0;i--)//length/2-1是第一个非叶节点，此处"/"为整除
    {
		HeapAdjust(data,i,len);
    }
	for (i=len-1;i>=0;i--)
	{
		swap(data[0],data[i]);
		HeapAdjust(data,0,i-1);
	}
}


//print Bitree
void Bitreeprint(BiNode *p)
{
  if(p!=NULL) 
  {
    Bitreeprint(p->lchild);
    printf("%d ",p->data);
    Bitreeprint(p->rchild);
  }//if
}//print
 
void main()
{
	BiNode *root = NULL;
    CreateBitree(root);
}
//crete test 
void CreateBitree(BiNode *root)
{
	int i;
	int num;
	int data[MAX];
	printf("请输入要输入值的个数\n");
	scanf("%d",&num);
	printf("请输入%d个值\n",num);
	for(i = 0;i < num;i++)
	{
      scanf("%d",&data[i]);
	}
	for(i = 0;i < num;i++)
	{
       root = Bitreeinsert(data[i],root);
	}
	Bitreeprint(root); 

}

//insert Bitree;input:root is tree's root. and data is data that you want to insert.
BiNode* Bitreeinsert(int data,BiNode *root)
{
     if(root == NULL)//空树的时候插入
	 {
		 root = (struct BiTreeNode *)malloc(sizeof(BiNode));
		 root->data = data;
		 root->lchild = NULL;
		 root->rchild = NULL;
		 return root;
	 }//if
	 if(root->data < data)
	 {
           root->rchild = Bitreeinsert(data,root->rchild);
	 }//if
	 else
	 {
		   root->lchild = Bitreeinsert(data,root->lchild);
	 }
	 return root;
}

