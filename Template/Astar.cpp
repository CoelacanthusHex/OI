#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>

const int sizeofpoint = 1024;
const int sizeofedge = 262144;

int N, M;
int S, T, K;
int d[sizeofpoint], t[sizeofpoint];

struct node {
    int u;
    int g;

    inline node(int _u, int _g) : u(_u), g(_g) {}
};
inline bool operator>(const node &, const node &);

struct edge {
    int point;
    int dist;
    edge *next;
};
inline edge *newedge(int, int, edge *);
inline void link(int, int, int);
edge memory[sizeofedge], *port = memory;
edge *e[sizeofpoint], *f[sizeofpoint];
std::priority_queue <node, std::vector<node>, std::greater<node> > h;

inline int getint();
inline void dijkstra(int);
inline int Astar();

int main() {
    N = getint(), M = getint();
    for (int i = 1; i <= M; i++) {
        int u = getint(), v = getint(), d = getint();
        link(u, v, d);
    }
    S = getint(), T = getint(), K = getint();
    dijkstra(T);

    if (d[S] == -1) {
        puts("-1");
        return 0;
    }

    K += S == T;

    printf("%d\n", Astar());

    return 0;
}

inline bool operator>(const node &u, const node &v) { return (u.g + d[u.u]) > (v.g + d[v.u]); }

inline edge *newedge(int point, int dist, edge *next) {
    edge *ret = port++;
    ret->point = point, ret->dist = dist, ret->next = next;
    return ret;
}
inline void link(int u, int v, int d) {
    e[v] = newedge(u, d, e[v]);
    f[u] = newedge(v, d, f[u]);
}

inline int getint() {
    register int num = 0;
    register char ch;
    do
        ch = getchar();
    while (ch < '0' || ch > '9');
    do
        num = num * 10 + ch - '0', ch = getchar();
    while (ch >= '0' && ch <= '9');
    return num;
}
inline void dijkstra(int S) {
    static int q[sizeofedge];
    static bool b[sizeofpoint];
    int l = 0, r = 0;

    memset(d, 0xFF, sizeof(d)), d[S] = 0;
    for (q[r++] = S, b[S] = true; l < r; l++) {
        int u = q[l];
        b[u] = false;
        for (edge *i = e[u]; i; i = i->next)
            if (d[i->point] == -1 || d[u] + i->dist < d[i->point]) {
                d[i->point] = d[u] + i->dist;
                if (!b[i->point]) {
                    b[i->point] = true;
                    q[r++] = i->point;
                }
            }
    }
}
inline int Astar() {
    h.push(node(S, 0));
    while (!h.empty()) {
        node p = h.top();
        h.pop();
        ++t[p.u];
        if (p.u == T && t[T] == K) return p.g;
        if (t[p.u] > K) continue;
        for (edge *i = f[p.u]; i; i = i->next) h.push(node(i->point, p.g + i->dist));
    }
    return -1;
}
