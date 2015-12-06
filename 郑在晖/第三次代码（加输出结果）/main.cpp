#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
map<string,int >p;
map<string ,int >::iterator iter;
int make(char s[100],int n,int k)
{
    char c;
    int i;
    if (k==n-1){
        iter=p.find(s);
        if (iter==p.end()){
            p.insert(pair<string ,int>(s,1));
        }else {
            iter->second++;
        }
    }else {
        for(i=k;i<n;i++){
            c=s[k];
            s[k]=s[i];
            s[i]=c;
            make(s,n,k+1);
            c=s[k];
            s[k]=s[i];
            s[i]=c;
        }
    }
}
int main()
{
    char s[100];
    int sum=0;
    int l;
    gets(s);
    l=strlen(s);
    make(s,l,0);
    cout<<"结果："<<endl;
    for(iter=p.begin();iter!=p.end();iter++){
        sum+=iter->second;
        cout<<iter->first<<endl;
    }
    cout<<"总数:"<<sum<<endl;
    return 0;
}
