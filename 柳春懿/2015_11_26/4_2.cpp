#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <malloc.h>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

char s[100];
char p[100];
int len;
FILE *fp, *fp1, *fp2;

//法二
void Print_permutation(int cur)
{
    if (cur == len){
       // fputs(p, fp1);
        return;
    }
    for (int i = 0; i < len; i++)
    if (!i || (s[i] != s[i-1]))
    {
        int c1 = 0;
        int c2 = 0;
        for (int j = 0; j < cur; j++)if (p[j] == s[i]) c1++;
        for ( j = 0; j < len; j++)if (s[j] == s[i]) c2++;
        if(c1<c2)
        {
            p[cur] = s[i];
            Print_permutation(cur+1);
        }

    }
}


int main()
{
char s[10]="123456789";
	len = strlen(s);
    sort(s, s+len);

    //法一
/*
    do{
        fputs(s, fp1);
    }while(next_permutation(s, s+len));

*/
    //法二
    Print_permutation(0);
    printf("Time used = %.2fs\n", (double)clock()/CLOCKS_PER_SEC);


	return 0;
}