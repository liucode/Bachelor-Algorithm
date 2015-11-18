/***
  1.给出一组整数对，｛(a[0],b[0]),(a[1],b[1])…(a[n-1],b[n-1]?｝，所有a值和b值分别不重复(任意i！=j满足a[i]！=a[j]，b[i]！=b[j])，构造一棵n结点的二叉树，将这两个整数对分配到各个结点上。根和所有的子树满足以下条件：
   (1)所有结点的a值满足二叉查找树的顺序，即left→a<root→a&&root→a<right→a。
   (2)所有结点b值满足最大堆的顺序，即root→b>left→b&&root→b>right→b。
              (2016校招阿里巴巴C++工程师笔试题目)
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
 
void swap(float &src,float &pat)//交换两组数据
{
    float temp;
	temp=src;
	src=pat;
	pat=temp;

}
