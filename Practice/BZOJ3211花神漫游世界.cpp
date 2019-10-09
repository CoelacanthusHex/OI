void pushup(int rt) {
    t[rt].tag = t[rt << 1].tag & t[rt << 1 | 1].tag;
    t[rt].sum = t[rt << 1].sum + t[rt << 1 | 1].sum;
}

void modify(int rt, int l, int r) {
    if (t[rt].l == t[rt].r) {
        t[rt].sum = sqrt(t[rt].sum);
        if (t[rt].sum == 0 || t[rt].sum == 1) t[rt].tag = 1;
        return;
    }
    if (t[rt].tag == 1) return;
    int mid = (t[rt].l + t[rt].r) >> 1;
    if (l <= mid) modify(rt << 1, l, r);
    if (mid < r) modify(rt << 1 | 1, l, r);
    pushup(rt);
}
