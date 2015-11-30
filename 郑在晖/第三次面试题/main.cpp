#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#define debug 1

using namespace std;
int s_p(int n)
{
    if (n==1){
        return 1;
    }
    return n*s_p(n-1);
}
void make1()
{
    char s[100];
    int sum[30],d,k,i;
    memset(sum,0,sizeof(sum));
    scanf("%s",&s);
    d=0;
    while(s[d]!='\0'){
        if (s[d]>='a'&&s[d]<='z'){
            sum[(int)(s[d]-'a')]++;
        }
        if (s[d]>='A'&&s[d]<='Z'){
            sum[(int)(s[d]-'A')]++;
        }
        d++;
    }
    k=s_p(strlen(s));
    for(i=0;i<26;i++){
        if (sum[i]!=0)
        k=k/sum[i];
    }
    printf("sum:%d\n",k);
}
void make()
{
    char s[100];
    int sum[60],d,k,i;
    memset(sum,0,sizeof(sum));
    scanf("%s",&s);
    d=0;
    while(s[d]!='\0'){
        if (s[d]>='a'&&s[d]<='z'){
            sum[(int)(s[d]-'a')]++;
        }
        if (s[d]>='A'&&s[d]<='Z'){
            sum[(int)(s[d]-'A')+26]++;
        }
        d++;
    }
    k=s_p(strlen(s));
    for(i=0;i<26+26;i++){
        if (sum[i]!=0)
        k=k/sum[i];
    }
    printf("sum:%d\n",k);
}
int main()
{
    int n,i,l;
    //freopen("input.txt","r",stdin);
    printf("不考虑字符过长的情况\n");
    printf("是否区分大小写：区分选择1：不区分选择2:");
    scanf("%d",&n);
    if (n==1){
        make();
    }else if (n==2){
        make1();
    }else {
        printf("error\n");
    }
    return 0;
}
