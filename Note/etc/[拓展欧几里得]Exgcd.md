# 欧几里得算法(辗转相除法)

> 原理: gcd(a, b) = gcd(b, a mod b)

```cpp
int gcd(int a, int b)
{
    return (b==0) ? a : gcd(b, a % b);
}
```

# 扩展欧几里得

> 扩展欧几里得不仅能求出 a,b 的最大公约数，还能求出满足 ax+by=gcd(a,b) 的一组可行解。

```cpp
int Exgcd(int a, int b, int &x, int &y)	//a, b为待求, x,y为可行解
{
    if (!b) { x=1, y=0; return a; }
    int d=Exgcd(b, a%b, x, y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
```

### PS: 求 ax+by=gcd(a,b) 的最小正整数解

```cpp
int Exgcd(int a, int b, int &x, int &y)	//a, b为待求, x,y为可行解
{
    if (!b) { x=1, y=0; return a; }
    int d=Exgcd(b, a%b, x, y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int cal(int a,int b,int c)
{
    int x,y;
    int gcd=Exgcd(a, b, x, y);
    if(c%gcd != 0) return -1;
    x *= c/gcd;//转化为a*x+b*y=c的解
    b /= gcd;//约去c后原来b就变为了b/gcd;
    if(b < 0) b = -b;//如果b为负数就去绝对值
    int ans = x%b;
    if(ans <= 0) ans += b;//求最小正整数解
    return ans;//返回的就是最小正整数解
}