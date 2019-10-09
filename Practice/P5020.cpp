#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, ans, n, a[10000];
bool f[30000];

int main() {
    cin >> t;
    for (int i = 1; i <= t;++i) {
        cin >> n;
        ans = n;
        memset(f, 0, sizeof(f));
        //memset(a, 0, sizeof(a));
        for (int j = 1; j <= n; ++j) {
            scanf("%d", a + j);
        }
        sort(a+1, a + n+1);
        for (int j = 1; j <= n; ++j) {
            if (f[a[j]]) {
                --ans;
                continue;
            } else {
                f[a[j]] = true;
                for (int k = a[j]; k <= a[n]; ++k) {
                    f[k] |= f[k - a[j]];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}