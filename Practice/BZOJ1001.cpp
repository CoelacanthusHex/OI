#include <cstdio>
#include <cstring>



#define oo 0x3f
#define MAXN 2000001
using namespace std;
struct edge {
    int v, to, next;
} e[MAXN * 2];
int dis[MAXN], q[MAXN], head[MAXN];
bool tag[MAXN];
int n, m, ne, x;
void insert(int u, int v, int w) {
    ne++;
    e[ne].to = v;
    e[ne].next = head[u];
    e[ne].v = w;
    head[u] = ne;
}
void spfa() {
    memset(dis, oo, sizeof(dis));
    int t = 0, w = 1;
    tag[0] = 1;
    q[w] = 0;
    dis[0] = 0;
    while (t != w) {
        int u = q[t++];
        tag[u] = 0;
        if (t == MAXN) t = 0;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].v) {
                dis[v] = dis[u] + e[i].v;
                if (tag[v] == 0) {
                    q[w++] = v;
                    tag[v] = 1;
                    if (w == MAXN) w = 0;
                }
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int nm = (n * m - n - m + 1) << 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &x);
            if (i == 1)
                insert(j, nm + 1, x);
            else if (i == n)
                insert(0, (((n - 1) << 1) - 1) * (m - 1) + j, x);
            else
                insert(((i - 1) << 1) * (m - 1) + j, (((i - 1) << 1) - 1) * (m - 1) + j, x);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &x);
            if (j == 1)
                insert(0, ((i << 1) - 1) * (m - 1) + 1, x);
            else if (j == m)
                insert(((i << 1) - 1) * (m - 1), nm + 1, x);
            else
                insert(((i - 1) << 1) * (m - 1) + j - 1, ((i << 1) - 1) * (m - 1) + j, x);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &x);
            insert((((i - 1) << 1) + 1) * (m - 1) + j, ((i - 1) << 1) * (m - 1) + j, x);
        }
    }
    spfa();
    printf("%d\n", dis[nm + 1]);
    return 0;
}
