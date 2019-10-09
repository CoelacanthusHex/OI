```cpp struct Node {
    int l, r;
    int sum;
} t[N << 2];

void pushup(int rt) { t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum; }

void build(int rt, int l, int r) {
    t[rt].l = l;
    t[rt].r = r;
    if (l == r) {
        t[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void modify(int rt, int p, int c) {
    if (t[rt].l == t[rt].r) {
        t[rt].sum = c;
        return;
    }
    int mid = (t[rt].l + t[rt].r) >> 1;
    if (p <= mid)
        modify(rt << 1, p, c);
    else
        modify(rt << 1 | 1, p, c);
    pushup(rt);
}

int query(int rt, int l, int r) {
    if (l <= t[rt].l && t[rt].r <= r) {
        return t[rt].sum;
    }
    int ret = 0;
    int mid = (t[rt].l + t[rt].r) >> 1;
    if (l <= mid) ret += query(rt << 1, l, r);
    if (mid < r) ret += query(rt << 1 | 1, l, r);
    return ret;
}
```
