## 1.朴素算法

	- if($d_A<d_B$)	swap(A, B);
	- 提升A至与B同深
	- 同时提升AB

## 2.

	- 定义 p[x][i] 表示 $x$ 的第 $2^i$ 个祖先
	- $p[x][i]=p[p[x][i-1]][i-1]$
	- $deld=d_A-d_B$
	- A=p[A][deld]


