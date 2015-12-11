#include <stdio.h>
#include <malloc.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

typedef  struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int total;
}*pNode;


void initNode(pNode node)
{
      node->data = 0;
	  node->total = 0;
	  node->left = NULL;
	  node->right = NULL;
}
void createTree(pNode head,int *data,int low,int high,int total,int flog)
{
	if(low > high)
	{
		return;
	}
	int ltotal = total;
	int rtotal = total;
	flog++;
	pNode left = (pNode)malloc(sizeof(struct Node)); 
	pNode right = (pNode)malloc(sizeof(struct Node)); 
	initNode(left);
	initNode(right);
	head->left = left;
	head->right = right;
	left->data = data[low];
	right->data = data[high];
	if(flog%2 != 0)
	{
			ltotal += left->data;
			rtotal += right->data;	
	}
	left->total = ltotal;
	right->total += rtotal;
	createTree(left,data,low+1,high,ltotal,flog);
	createTree(right,data,low,high-1,rtotal,flog);	
}


void printTree(pNode root)//广度优先
{
	int num = 0;
	int cnum = 1;
    queue<pNode> nodeQueue;  //使用C++的STL标准模板库
    nodeQueue.push(root);
    pNode node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        printf("%d ", node->total);
		num++;
		if(num == cnum)
		{
			num = 0;
			cnum  = 2*cnum;
			printf("\n");
		}
        if(node->left){
            nodeQueue.push(node->left);  //先将左子树入队
        }
        if(node->right){
           nodeQueue.push(node->right);  //再将右子树入队
        }
    }
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int MaxValue(int v[], const int len) {
    int r[100][100], s[100][100]; 
    int n = len - 1;
	int i,j;
    for ( i = 0; i < len; i++) {
        r[i][i] = v[i];
        s[i][i] = v[i];
    }
    for ( i = len - 2; i >= 0; i--) {
        for (j = i + 1; j < len; j++) {
            int sum = s[i][j] = v[i] + s[i + 1][j];
            r[i][j] = max(sum - r[i + 1][j], sum - r[i][j - 1]);
        }
    }
	for(i = 0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(j<i)
				printf("0 ");
			else
				printf("%d ",r[i][j]);
		}
		printf("\n");
	}
	for(i = 0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(j<i)
				printf("0 ");
			else
				printf("%d ",s[i][j]);
		}
		printf("\n");
	}
    return r[0][len - 1];
}

void main()
{
	int data[6] = {2,3,100,50,1,20};
	pNode head = (pNode)malloc(sizeof(struct Node));  
	initNode(head);
    createTree(head,data,0,3,0,0);
    printTree(head);
	printf("%d ",MaxValue(data,6));


}



 
