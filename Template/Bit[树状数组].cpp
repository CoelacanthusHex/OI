int lowbit(int x) { return x & (-x); }

void modify(int x, int y) {
    // add y to a[x]
    for (int i = x; i <= n; i += lowbit(i)) c[i] += y;
}

int query(int x) {
    // sum of a[1]...a[x]
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += c[i];
    return ret;
}

int query(int l, int r) { return query(r) - query(l - 1); }
