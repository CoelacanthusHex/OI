```cpp
    /*
            欧拉筛

            筛数 i
            选取一个素数 p
            把 p * i 筛掉
            此时会检查 i 的最小素因子是否是p
            所以有两种可能：
            1、i 和 p 互素
                    phi[i * p] = phi[i] * phi[p]
            2、i 的最小素因子刚好是 p
                    phi[i * p] = phi[i] * p
    */


bool notprime[];
int tot, prime[], e[];
int phi[];  // phi 是欧拉函数
int g[];    // g[n]表示n的因子个数
int f[];    // f[n]表示n的最小素因子的次数
            //	f[12] = 2;
            // f[81] = 4;
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            prime[tot++] = i;
            e[i] = i;
            phi[i] = i - 1;
            g[i] = 2;
            f[i] = 1;
        }
        for (int j = 0; j < tot && (k = prime[j] * i) < n; j++) {
            e[k] = prime[j];
            notprime[k] = true;
            if (e[i] == prime[j]) {
                phi[k] = phi[i] * prime[j];
                f[k] = f[i] + 1;
                g[k] = g[i] / (f[i] + 1) * (f[k] + 1);
                break;
            } else {
                phi[k] = phi[i] * phi[prime[j]];
                g[k] = g[i] * g[prime[j]];
                f[k] = 1;
            }
        }
    }
}
```