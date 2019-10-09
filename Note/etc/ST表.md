## 思路历程

1. 要求区间最大值, 想法是记录$f(i,j)$是$[i,j]$内最大值, 有$f(i,j) = \max(f(i,j - 1), a_j)$,但为$O(N^2)$

2.  $\max$ 操作允许区间重叠，也就是 $\max(a,b,c)=\max(\max(a,b),\max(b,c))$

3. 采用倍增思想，令 $f(i,j)$ 为从 $a_i$开始的、连续 $2^j$个数的最大值，显然：

    $f(i,0)=a_i$

    $f(i,j)=\max(f(i,j-1),f(i+2^{j-1},j-1)$

    在这种方式下，以每个点为起点都有 $logN$个区间，每个区间可以 $O(1)$求出，则预处理总时间、空间复杂度都为 $O(NlogN)$ 

4. 根据 $\max$ 的性质，我们可以把区间拆成两个相重叠的区间

    记询问区间长度为 $len$ ，我们从左端点向右找一段长为 $2^{log(len)} $
    的区间，右端点向左也找一段长为 $2^{log(len)}$的区间，显然这两段区间已经覆盖了整个区间(中间重叠了一块)，取最大值即可

5. 为了保证询问复杂度为 $O(1)$ ，我们需要提前预处理出每个 $log(len)$向下取整后的值。整个算法总时间复杂度为 $O(NlogN+M)$

## 适用范围

满足**允许区间重叠**的**静态**问题

## 代码实现

```cpp
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100001]={};
int lg[100001]={-1};
int maxn[100001][50]={};

int main()
{
    int n=0,m=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        lg[i]=lg[i/2]+1;
    }
    for(int i=1;i<=n;i++)
    {
        maxn[i][0]=a[i];
    }
    //puts("OK");
    for(int i=1;i<=lg[n];i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            maxn[j][i]=max(maxn[j][i-1],maxn[j+(1<<(i-1))][i-1]);
        }
        //puts("OK");
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;i+(1<<j)-1<=n;j++)
        {
            printf("%d ",maxn[i][j]);
        }puts("");
    }*/
    int l=0,r=0;
    while(m--)
    {
        scanf("%d%d",&l,&r);
        int len=lg[r-l+1];
        printf("%d\n",max(maxn[l][len],maxn[r-(1<<(len))+1][len]));
    }
    return 0;
}
```





