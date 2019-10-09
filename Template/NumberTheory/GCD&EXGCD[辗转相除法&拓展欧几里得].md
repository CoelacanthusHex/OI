## 1.辗转相除法

```cpp
int gcd(int x, int y)
{
    if(!y)	return x;
    else return gcd(y, x % y);
}
```

## 2.拓展欧几里得

### 2.1.裴蜀定理
>	(x, y) = d	==>	存在无限多组整数 a，b  :  ax + by = d

### 2.2. Template
```cpp
void exgcd(int a, int b, int &gcd, int &x, int &y)
{
	if(!y)	gcd = x, x = 1, y = 0;
	else	exgcd(b, a % b, gcd, x, y), y -= x*(a/b)
}
```
### 2.3逆元

##### 2.3.1.定义:	如果 $x$ 对 $p$ 有一个逆元 $y$，则 $x * y == 1 (mod p)$

##### 2.3.2.充要条件: $x$ 对一个数 $p$ 有逆元当且仅当 $(x, p) = 1$

### 2.4.求解 $x$ 对 $p$ 的逆元

```cpp
int inv(int x, int p)
{
	int d, a, b;
    exgcd(x, p, d, a, b);
    return (a + b) % p;
}
```




### 2.5. $1!-n!$ 对 $p$ 逆元

>	打表$f[n]=n!$, $n!$对$p$的逆元$g[n]$, 利用$g[n-1]=n*g[n]$

### 2.6. $1-n$对 $p$ 的逆元

```cpp
t = p/n;
k = p%n;
n^-1 = n*t^2*f(k)^2 mod p
```

## 3.快速最大公约数算法

```cpp
int gcd(int x, int y)
{
    if(!x)	return y;
    if(!y)	return x;
    if(!(x & 1) && !(y & 1))
        return gcd(x >> 1, y >> 1) << 1;
    else if(!(x & 1))
        return gcd(x >> 1, y);
    else if(!(y & 1))
        return gcd(x, y >> 1);
    return gcd(abs(x - y), min(x, y));
}
```

## 4.中国剩余定理求解同余方程组

方程: $x = a_i\ (mod\ p_i)$

$P=\prod_{i=1}^n{p_i}$

$P_i=\frac{P}{p_i}$

$Q_i=P_i^{-1}\ mod\ p_i$

$x=\sum{a_i*P_i*Q_i}$





