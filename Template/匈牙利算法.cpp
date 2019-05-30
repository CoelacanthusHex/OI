#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define rint register int

using namespace std;

const int MAXN=1e7; 

vector <int> e[MAXN];
int book[MAXN], match[MAXN];
int tmp, m, n, u, v, es, sum;

inline void add_edge(int a, int b)
{
    if(b>m||a>n) return;
    e[a].push_back(b);
}

bool dfs(int u)
{
    vector<edge>::iterator en=e[u].end();
    for(vector<edge>::iterator i=e[u].begin() ; i<en ;++i)
    {
        rint tmp=*i;
        if(book[tmp]==0)
        {
            book[tmp]=1;
            if(match[tmp]==0 || dfs(match[tmp]))
            {
                match[tmp]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m >> es;
    for(rint i=0;i<es;++i)
    {
        cin >> u >> v;
        add_edge(u, v);
    }
    rint sizet=m+n;
    for(rint i=0;i<sizet;++i)
    {
        memset(book, 0, sizeof(book));
        if(dfs(i)) ++sum;
    }
    cout << sum;
    return 0;
}
