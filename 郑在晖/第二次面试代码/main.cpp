#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#define debug 1
using namespace std;
int n;
int a[1000];
void make()
{
    int i;
    int d,maxx,p;
    d=0;
    printf("%d",a[d]);
    while(1){
        i=d;
        maxx=0;
        p=d;
        if (a[d]+d>=n-1){
            printf("->%d\n",a[n-1]);
            break;
        }
        for(i=d+1;i<=a[d]+d;i++){
            if (a[i]+i>=maxx){
                maxx=a[i]+i;
                p=i;
            }
        }
        printf("->%d",a[p]);
        d=p;
    }
}
//13 4,6,2,5,1,3,0,4,8,1,5,3,6
 int f[1000];
void su(int d)
{
    if (d==0){
        printf("%d->",a[d]);
        return ;
    }
    su(f[d]);
    if (d!=n-1)
    printf("%d->",a[d]);
    else {
        printf("%d",a[d]);
    }
}
void bfs()
{
    int i,s;
    int d=0;
    queue<int>q;
    q.push(0);
    for(i=0;i<n;i++){
        f[i]=-1;
    }
    f[d]=d;
    while(!q.empty()){
        s=q.front();
        //printf("s:%d\n",s);
        q.pop();
        for(i=s+1;i<=a[s]+s;i++){
            //printf("%d\n",i);
            if (i==n-1){
                f[n-1]=s;
                break;
            }
            if (f[i]==-1){
                f[i]=s;
                q.push(i);
            }
        }
        if(f[n-1]!=-1){break;}
    }
    su(n-1);
}
int main()
{
    int i;
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    //Ì°ÐÄ
    printf("Ì°ÐÄ:");
    make();
    //bfs
    printf("bfs:");
    bfs();
    return 0;
}
