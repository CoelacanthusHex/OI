##快速幂


    int
    power(int ret, int p) {
    int a = 1;
    while (p) {
        if (p & 1) ret = ret * a;
        a = a * a;
    }
    return ret;
}


##矩阵快速幂


    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= tmp; k++)
        c.m[i][j] = x.m[i][k] * y.m[k][j];
