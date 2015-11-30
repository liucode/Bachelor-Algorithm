
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 10;
const int nodemaxn = 1e4 + 5;
char s[10005][11];
struct Trie{
    Trie *next[maxn];
    bool in;
    Trie()
    {
        memset(next, 0, sizeof(next));
        in = false;
    }
};
Trie *root;
void init()
{
    root = new Trie;
}
void Insert(char *s)
{
    if (!s[0]) return;
    Trie *p = root;
    for (int i = 0; s[i]; i++)
    {
        if  (!p -> next[s[i]-'0'])
            p -> next[s[i]-'0'] = new Trie;
        p -> in = true;
        p = p -> next[s[i]-'0'];
    }

}
bool Query(char *s)
{
    if (!s[0]) return false;
    Trie *p = root;
    for (int i = 0; s[i]; i++)
    {
        if (!p -> next[s[i]-'0']) return false;
        p = p ->next[s[i]-'0'];
    }
    if (p -> in)
    {
        return true;
    }
    return false;
}
void Delete(Trie *t)
{
    if (!t) return;
    for (int i = 0; i < maxn; i++)
    {
        if (t->next[i])
            Delete(t->next[i]);
    }
    delete t;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        init();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s[i]);
            Insert(s[i]);
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (Query(s[i]))
            {
                flag = 1;
                break;
            }
        }
        if (flag) puts("NO");
        else puts("YES");
        Delete(root);
    }


    return 0;
}
