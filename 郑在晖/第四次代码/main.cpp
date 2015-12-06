#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef struct st{
        char s2[5];
        int k;
}node;
//vector<struct st> sum(101);
node sum[101];
int cmp(node x,node y)
{
    if (x.k!=y.k){
        return x.k>y.k;
    }else {
        //return 1;
        return(!strcmp(x.s2,y.s2));
    }
}
int main()
{
    map<string,int>p;
    map<string ,int >::iterator iter;
    char s[100];
    char s1[5];
    int d;
    scanf("%s",&s);
    int l=strlen(s);
    int i;
    i=0;
    for(i=0;i<l;i++){
        s1[0]=s[i];
        s1[1]='\0';
        iter=p.find(s1);
        if (iter==p.end()){
            p.insert(pair<string,int>(s1,1));
        }else {
            iter->second++;
        }
        if (i+1<l){
            s1[1]=s[i+1];
            s1[2]='\0';
            iter=p.find(s1);
            if (iter==p.end()){
               p.insert(pair<string,int>(s1,1));
            }else {
                    iter->second++;
            }
        }
        if (i+2<l){
            s1[2]=s[i+2];
            s1[3]='\0';
            iter=p.find(s1);
            if (iter==p.end()){
                p.insert(pair<string,int>(s1,1));
            }else {
                    iter->second++;
            }
        }
    }
    d=0;
    for(iter=p.begin();iter!=p.end();iter++){
        strcpy(sum[d].s2,iter->first.data());
        //printf("%s ",sum[d].s2);
        sum[d].k=iter->second;
        //printf("%d\n",sum[d].k);
        d++;
    }
    sort(sum,sum+d,cmp);
    for(i=0;i<d;i++){
        printf("%s %d\n",sum[i].s2,sum[i].k);
    }
    return 0;
}
