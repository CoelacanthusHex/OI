#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxm=2001,maxn=101;
int n,m,v,i;
int c[maxn],w[maxn];
int f[maxm];
int main()
{
    scanf("%d%d",&m,&n);            //背包容量m和物品数量n
    for(i=1;i<=n;i++) 
        scanf("%d%d",&w[i],&c[i]);
    for(i=1;i<=n;i++)
        for(v=w[i]; v<=m; v++)          //设 f[v]表示重量不超过v公斤的最大价值
                                        //这里是v++ 顺序 区别于01背包 
            f[v]=max(f[v-w[i]]+c[i], f[v]);
    printf("%d\n", f[m]);           // f[m]为最优解
    return 0;
}
/*有N种物品和一个容量为V的背包，每种物品都有无限件可用。
第i种物品的费用是w[i]，价值是c[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

完全背包和01背包十分相像， 区别就是完全背包物品有无限件。
由之前的选或者不选转变成了选或者不选，选几件。√

和01背包一样，我们可以写出状态转移方程：
f[i][v]=max(f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v)

还有一个简单的优化↓_↓

当一个物品的价值小于另一个物品的价值，但是价格高于另一个物品，
我们就可以不去考虑这个物品。即若两件物品i、j满足c[i]<=c[j]且w[i]>=w[j]，
则将物品j去掉，不用考虑。我们为什么要买一个又贵又难吃的东西呢(╯▽╰)
