int fa[N], ch[N][2];
int cnt[N];
int data[N];
int siz[N];

int son(int x) { return x == ch[fa[x]][1]; }

void pushup(int rt) { siz[rt] = siz[ch[rt][0]] + siz[ch[rt][1]] + cnt[rt]; }

void rotate(int x) {
    int y = fa[x], z = fa[y], b = son(x), c = son(y), a = ch[x][!b];
    if (z)
        ch[z][c] = x;
    else
        root = x;
    fa[x] = z;
    if (a) fa[a] = y;
    ch[y][b] = a;
    ch[x][!b] = y;
    fa[y] = x;
    pushup(y);
    pushup(x);
}

void splay(int x, int i) {
    while (fa[x] != i) {
        int y = fa[x], z = fa[y];
        if (z == i) {
            rotate(x);
        } else {
            if (son(x) == son(y)) {
                rotate(y);
                rotate(x);
            } else {
                rotate(x);
                rotate(x);
            }
        }
    }
}

//插入x数
void insert(int &rt, int x) {
    if (rt == 0) {
        rt = ++nn;
        data[rt] = x;
        siz[rt] = cnt[rt] = 1;
        return;
    }
    if (x == data[rt]) {
        cnt[rt]++;
        siz[rt]++;
        return;
    }
    if (x < data[rt]) {
        insert(ch[rt][0], x);
        fa[ch[rt][0]] = rt;
        pushup(rt);
    } else {
        insert(ch[rt][1], x);
        fa[ch[rt][1]] = rt;
        pushup(rt);
    }
}

//求x的前驱(前驱定义为小于x，且最大的数)
int getpre(int rt, int x) {
    int p = rt, ans;
    while (p) {
        if (x <= data[p]) {
            p = ch[p][0];
        } else {
            ans = p;
            p = ch[p][1];
        }
    }
    return ans;
}

//求x的后继(后继定义为大于x，且最小的数)
int getsuc(int rt, int x) {
    int p = rt, ans;
    while (p) {
        if (x >= data[p]) {
            p = ch[p][1];
        } else {
            ans = p;
            p = ch[p][0];
        }
    }
    return ans;
}

int getmn(int rt) {
    int p = rt, ans = -1;
    while (p) {
        ans = p;
        p = ch[p][0];
    }
    return ans;
}

//删除x数(若有多个相同的数，因只删除一个)
void del(int rt, int x) {
    if (data[rt] == x) {
        if (cnt[rt] > 1) {
            cnt[rt]--;
            siz[rt]--;
        } else {
            splay(rt, 0);
            int p = getmn(ch[rt][1]);
            if (p == -1) {
                root = ch[rt][0];
                fa[ch[rt][0]] = 0;
            } else {
                splay(p, rt);
                root = p;
                fa[p] = 0;
                ch[p][0] = ch[rt][0];
                fa[ch[rt][0]] = p;
                pushup(p);
            }
        }
        return;
    }
    if (x < data[rt]) {
        del(ch[rt][0], x);
    } else {
        del(ch[rt][1], x);
    }
    pushup(rt);
}

// 查询x数的排名(若有多个相同的数，因输出最小的排名)
int getk(int rt, int k) {
    if (data[rt] == k) {
        splay(rt, 0);
        if (ch[rt][0] == 0) {
            return 1;
        } else {
            return siz[ch[rt][0]] + 1;
        }
    }
    if (k < data[rt]) return getk(ch[rt][0], k);
    if (data[rt] < k) return getk(ch[rt][1], k);
}

查询排名为x的数 int getkth(int rt, int k) {
    int l = ch[rt][0];
    if (siz[l] + 1 <= k && k <= siz[l] + cnt[rt]) return data[rt];
    if (k < siz[l] + 1)
        return getkth(l, k);
    else
        return getkth(ch[rt][1], k - siz[l] - cnt[rt]);
}
