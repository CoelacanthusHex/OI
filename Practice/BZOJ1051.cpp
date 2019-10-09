void tarjan(int u) {
    dfn[u] = ++ind;
    low[u] = dfn[u];
    s[top++] = u;
    in[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (dfn[v] == 0) {  // mei bian li dao, v zai zi shu li mian
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {          // bian li dao le, v bu zai zi shu li mian
            if (in[v]) {  // zai zhan li mian
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    if (dfn[u] == low[u]) {  // fa xian scc
        cnt_scc++;
        while (s[top] != u) {  // bu duan chu zhan
            top--;
            in[s[top]] = 0;
            scc[s[top]] = cnt_scc;
        }
    }
}
