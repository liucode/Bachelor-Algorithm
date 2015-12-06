#include <stdio.h>
#include <string.h>
struct Node
{
	char str[4];
	int count;
	int flog;
};

void nodecp(struct Node* nodeA,struct Node* nodeB)
{
	for(int i=0;i<4;i++)
		nodeA->str[i]=nodeB->str[i];
	nodeA->count = nodeB->count;
	nodeA->flog = nodeB->flog;
}
int comp(struct Node *nodeA,struct Node *nodeB)
{
	if(nodeA->count<nodeB->count)
	{
		return 1;
	}
	else if(nodeA->count == nodeB->count)
	{
		if(!strcmp(nodeA->str,nodeB->str))
		{
			nodeA->flog = -1;
			nodeB->count++;
		}
		if(strcmp(nodeA->str,nodeB->str)>0)
		{
			return 1;
		}
	}
	return 0;

}

void main()
{
	 char str[100];
	 struct Node node[100];
     FILE *fp = fopen("input.txt","r");
	 fscanf(fp,"%s",str);
	 int i,j;
	 int len = strlen(str);
	 for(i=0;i<len;i++)
	 {
			 node[i].str[0] = str[i];
			 node[i].str[1] = '\0';
			 node[i].count = 1;
			 node[i].flog = 1;
			 if(i<len-1)
			 {
				node[i+len].str[0] = str[i];
				node[i+len].str[1] = str[i+1];
				node[i+len].str[2] = '\0';
				node[i+len].count = 1;
				node[i+len].flog = 1;
			 }
			 if(i<len-2)
			 {
			   node[i+len+len-1].str[0] = str[i];
			   node[i+len+len-1].str[1] = str[i+1];
			   node[i+len+len-1].str[2] = str[i+2];
			   node[i+len+len-1].str[3] = '\0';
			   node[i+len+len-1].count = 1;
			   node[i+2*len-1].flog = 1;
			 }
	}
	 struct Node temp;
    for(i=0;i<3*len-3;i++)
		for(j=i+1;j<3*len-3;j++)
		{
			if(comp(&node[i],&node[j]))
			{
                nodecp(&temp,&node[i]);
				nodecp(&node[i],&node[j]);
				nodecp(&node[j],&temp);
			}

		}
		for(i=0;i<3*len-3;i++)
		{
			if(node[i].flog!= -1)
				printf("%s %d \n",node[i].str,node[i].count);

		}
}