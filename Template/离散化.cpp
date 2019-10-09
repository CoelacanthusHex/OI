for (int i = 1; i <= n; i++) t[i] = a[i];
sort(t + 1, t + 1 + n);
int tmp = unique(t + 1, t + 1 + n) - t - 1;
for (int i = 1; i <= n; i++) a[i] = lower_bound(t + 1, t + 1 + tmp, a[i]) - t;
