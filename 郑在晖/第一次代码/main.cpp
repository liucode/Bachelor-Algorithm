#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define large 1000
#define DEBUG true
using namespace std;
struct st{
    int a;
    int b;
    //struct st *left,*right;
    int left,right;
}Node[large];
int cmp(struct st x,struct st y)
{
    return x.b>y.b;
}
int cmpa(struct st x,struct st y)
{
    return x.a<y.a;
}
int make(int be,int en)
{
    int i,j;
    int point;
    if (be==en){
        return be;
    }
    point=be;
    for(i=be+1;i<=en;i++){
        if(Node[i].b>Node[point].b){
            point=i;
        }
    }
    if (be<=point-1){
        //Node[point].left=&Node[make(be,point-1)];
        Node[point].left=make(be,point-1);
    }else {
        //Node[point].left=NULL;
        Node[point].left=-1;
    }
    if (point+1<=en){
        //Node[point].right=&Node[make(point+1,en)];
        Node[point].right=make(point+1,en);
    }else {
        //Node[point].right=NULL;
        Node[point].right=-1;
    }
    return point;
}
void dfs(int point)
{
    printf("(%d,%d)->",Node[point].a,Node[point].b);
    if (Node[point].left!=-1){
        dfs(Node[point].left);
    }
    if (Node[point].right!=-1){
        dfs(Node[point].right);
    }
}
int main()
{
    int n,i,point;
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&Node[i].a,&Node[i].b);
        Node[i].left=-1;
        Node[i].right=-1;
    }
    sort(Node,Node+n,cmpa);
    point=make(0,n-1);
    if (DEBUG){
        for(i=0;i<n;i++){
            printf("%d %d\n",Node[i].a,Node[i].b);
        }
    }
    dfs(point);
    return 0;
}
