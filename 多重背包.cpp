//原代码
//先给出一个未优化的朴素算法
#include<stdio.h>
#include<algorithm>
using namespace std;
int v[6002], w[6002], s[6002];
int f[6002];
int n, m;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    for (int i = 1; i <= n; i++)
       for (int j = m; j >= 0; j--)
          for (int k = 0; k <= s[i]; k++)
          {
               if (j-k*v[i]<0) break;
               f[j] = max(f[j],f[j-k*v[i]]+k*w[i]);
          }
    printf("%d\n",f[m]);
    return 0;
}

//进行二进制优化，转换为01背包（拆分物品）
#include<stdio.h>
#include<algorithm>
using namespace std;
int v[10001],w[10001];
int f[6001];
int n,m,n1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y,s,t=1;
        scanf("%d%d%d",&x,&y,&s);
        while (s>=t) 
        {
            v[++n1]=x*t;
            w[n1]=y*t;
            s-=t;
            t*=2;
        }
        v[++n1]=x*s;
        w[n1]=y*s;                             //把s以2的指数分堆：1，2，4，…，2^(k-1)，s-2^k+1,
    }
for(int i=1;i<=n1;i++)
        for(int j=m;j>=v[i];j--)
           f[j]=max(f[j],f[j-v[i]]+w[i]); 
    printf("%d\n",f[m]);
    return 0;
}

/*三、多重背包

有N种物品和一个容量为V的背包。第i种物品最多有n[i]件可用，每件费用是w[i]，价值是c[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

这里又多了一个限制条件，每个物品规定了可用的次数。

同理，我们可以得出状态转移方程：f[i][v]=max(f[i-1][v-k*w[i]]+ k*c[i]|0<=k<=n[i])

一道例题↓_↓

庆功会

【问题描述】

为了庆贺班级在校运动会上取得全校第一名成绩，班主任决定开一场庆功会，
为此拨款购买奖品犒劳运动员。期望拨款金额能购买最大价值的奖品，可以补充他们的精力和体力。

【输入格式】

第一行二个数n(n<=500)，m(m<=6000)，其中n代表希望购买的奖品的种数，m表示拨款金额。 
接下来n行，每行3个数，v、w、s，分别表示第I种奖品的价格、价值（价格与价值是不同的概念）
和购买的数量（买0件到s件均可），其中v<=100，w<=1000，s<=10。

【输出格式】

第一行：一个数，表示此次购买能获得的最大的价值（注意！不是价格）。

【输入样例】

5 1000

80 20 4

40 50 9

30 50 7

40 30 6

20 20 1

【输出样例】

1040

 
