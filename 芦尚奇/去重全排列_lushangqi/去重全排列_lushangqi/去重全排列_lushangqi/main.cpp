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
int cnt[100];
int pre_cnt[100];
int len;
FILE *fp, *fp1;

//法二
void Print_permutation(int cur)
{
    if (cur == len)
    {
        fputs(p, fp1);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!i || (s[i] != s[i-1]))
        {
            int c1 = 0;
            //我觉得此部分for循环如果优化的话就要记录所有的字符
            //在字符串中的次数，就要用到回溯法了，而for循环的时间复杂度也由
            //o(n)转为o（logn）对于字符串长度较短来说，优化程度不大
            //有兴趣可以试试
            for (int j = 0; j < cur; j++)if (p[j] == s[i]) c1++;

            if(c1<cnt[cur])
            {
                p[cur] = s[i];

                Print_permutation(cur+1);
            }
        }
        else
        {
            while (s[i] == s[i-1])i++;
        }
    }

}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fp = fopen("input.txt", "r");
    fp1 = fopen("output.txt", "r");
    fscanf(fp, "%s", s);
    len = strlen(s);
    sort(s, s+len);//排序，输出时按字典序输出

    memset(pre_cnt, 0, sizeof(pre_cnt));
    memset(cnt, 0, sizeof(cnt));
    //预处理，每个字符在整个字符串中出现的次数
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
            if (s[i] == s[j])
                cnt[i]++;
    }

    //法一,c++STL的一个排列函数
    /*
    do
    {
        fputs(s, fp1);
    }
    while(next_permutation(s, s+len));
    */

    //法二
    Print_permutation(0);
    printf("Time used = %.2fs\n", (double)clock()/CLOCKS_PER_SEC);


    return 0;
}
