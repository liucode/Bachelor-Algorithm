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

//����
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
            //�Ҿ��ô˲���forѭ������Ż��Ļ���Ҫ��¼���е��ַ�
            //���ַ����еĴ�������Ҫ�õ����ݷ��ˣ���forѭ����ʱ�临�Ӷ�Ҳ��
            //o(n)תΪo��logn�������ַ������Ƚ϶���˵���Ż��̶Ȳ���
            //����Ȥ��������
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
    sort(s, s+len);//�������ʱ���ֵ������

    memset(pre_cnt, 0, sizeof(pre_cnt));
    memset(cnt, 0, sizeof(cnt));
    //Ԥ����ÿ���ַ��������ַ����г��ֵĴ���
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
            if (s[i] == s[j])
                cnt[i]++;
    }

    //��һ,c++STL��һ�����к���
    /*
    do
    {
        fputs(s, fp1);
    }
    while(next_permutation(s, s+len));
    */

    //����
    Print_permutation(0);
    printf("Time used = %.2fs\n", (double)clock()/CLOCKS_PER_SEC);


    return 0;
}
