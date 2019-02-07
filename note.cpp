Day 1:

A.M.

{}//代码块

质数: 	n=a*b;//(a<=b)
		n>=a^2;
		a<=sqrt(n);
	所以:
		int n,s;
		cin>>n;
		s=sqrt(n);
		for(i=2;i<=s;i++)
	或	for(i=2;i*i<=n;i++) 
		{
			------;
		}
		
函数名可以相同:
	但参数个数（不可以是参数类型）必须不同!!! 
	int sum(int a,int b)
	{
		return a+b+c;
	}
		int sum(int a,int b,int c)
	{
		return a+b+c;
	}
	合并后:
	int sum(int a,int b=0,int c=0)//函数默认值
	{
		return a+b+c;
	}
	错误写法:
	int sum(int a,int b=0,int c)//有默认值的参数必须放在没有默认值的参数后面 
	{
		return a+b+c;
	} 

	//所有数组开成全局变量!!!
	栈空间、堆空间:
	栈空间:用于存局部变量与参数;(没有空间限制,内存很小,由系统决定); 
	堆空间:用于存全局变量; (有空间限制,内存比较大,由空间限制决定);
	
memset:
	赋值0/-1: 
		memset(a,0,sizeof(a)) ;
		memset(a,-1,sizeof(a)) ;
	将值设为无穷大: 
		memset(a,0x7f,sizeof(a)) ;//0x7f--->0x7f7f7f7f==2139062143
		memset(a,0x3f,sizeof(a)) ;//0x3f--->0x3f3f3f3f==1061109567
	
读入字符串: 计算长度: 
	cin>>s;//s[6]
	strlen(s);
	
	cin>>s+1;//s[7]
	strlen(s+1);//注意：括号中为"s+1" 
	
	#include <cmath>:
	整数的绝对值:abs(-1)	
	实数、浮点数的绝对值:fabs()
	正弦函数，单位弧度:sin(1.0)
	反正弦函数:asin(1.0)
	
	
	
	e^x:exp(x)
	ln x:log(x)
	lg x:log10(x)
	x^y:pow(x,y)
	
	//结果为实数 
	下取整:floor(3.7)==3.0; 
	上取整:ceil(3.7)==4.0;
	四舍五入:round(3.5)==4.0;
	
数据类型: 
		bool				(0~256)			1B
		char				(-128~127)		1B
							(其中(0---127)为ASCII码)
							0:'\0';
							10:'\n';
							32:' '
							48~57:1~9;
					
					
					
							4个字符表示1个汉字； 
		
	整型：	
		int					(-2^31~2^31-1)	4B
							x=2^31-1;
							cout<<x+1<<endl;	Reaslt:-2^31
							INT_MAX=2^31-1==2147483647~=2E9
		unsigned_int 		(0~2^32-1)		4B
		long long			(-2^63~2^63-1)	8B
								2^63-1~=4E18
		unsigned long long	(0~2^64-1)		8B
			//int 的计算速度是 long long 的2倍
	E6个 	char/bool --->1MB
			int/unsigned_int --->4MB
			long long /unsigned long long --->8MB
	
	实型：
		float	
		double								8B
		long double
		
		Pie的计算	PI=acos(-1.0);//由三角函数得到
		
P.M.
	
结构体：
	//c++不会主动给结构体变量初始化
	手动初始化:
		struct jiegoutiname
		{
			int a;
			char b;
			
			//结构体构造函数(结构体初始化)
			jiegoutiname()
			{
				a=0;
				b=0;
			}
		};
	//当函数的返回值为数组时时必须使用结构体(使用结构体包装数组)

输入输出:
	cout:
		#include <iomanip>
		cout<<a<< /*sentence*/<<endl;
		setprecision(x)			保留x位小数
	格式化输入输出:
		#include <cstdio>
		//模式字符串和变量一一对应
		scanf:
			scanf("%d%c%s",&a，&b,str);//%d占位符
			%d		int 整型
			%c 		char 字符型
			%s		string 字符串(字符数组）	//str底层为地址
			%lf		double 
			%lld 	long long (windows32位系统用%I64d，windows64位皆可，其他系统用%lld)
			%I64d	用条件编译解决问题：
						#ifdef WIN32
						#define LL "%I64d"
						#else
						#define LL "%lld"
						#endif
						scanf(LL,&a);
			//模式字符串	
				e.g.	1972-4-56格式日期读入
						scanf("%d-%d-%d",&year,&month,&day);
				
			
		printf:
			printf("%d\n",a);
			%d 		int整型
			%c 		char 字符型
			%lf		double 
			%m.n	小数点前m位，小数点后n位
			%lld	long long 同上 printf(LL \n,a);
	输入输出优化:
		一、输出
			1.cout比printf快
			2.cout中换行使用\n比endl快
			3. ios::sync_with_stdio(false);//关闭流同步,没有优化效果，用后不能用scanf，printf
		二、输入
			1. ios::sync_with_stdio(false);//关闭流同步,对cout有效果，用后不能用scanf，printf
			2.readint(读入优化) > cin sync > scanf > cin
			3.读入优化		//一个字符一个字符地读
				int readint()				//整数读入
				{
					char c=' ';
					while(c<'0'||c>'9')		//寻找所需数
						c=getchar();
					int x=0;
					while(c>='0'&&c<='9')	//读数
					{
						x+10*x+c-'0';
						c=getchar();
					}
					return x;
				}
	文件输入输出:
		#include <cstdio>
		freopen("in.txt","r",stdin);//读入
		freopen("out.txt","w",stdout);//输出
	
基本数据结构:
	1.数组:线性，访问元素时间O(1),删除、插入元素时间O(n)
	2.链表:线性，访问元素时间O(n),删除、插入元素时间O(1)
		实现一:
			struct node
			{
				int next,pre;
				int data;
				node()
				{
					next=pre=0;
					data=0;
				}
			};
			int firet=0,n=0;
			
			void insert(int i,int v)
			{
				n+=1;
				list[n].data=v;
				list[n].pre=i;
				list[n].next=list[i].next;
				list[list[i].next].pre=n;
				
			}
			void delede(int i)
			{
				int pre=list[i].pre;
				int next=list[i].next;
				list[pre]=pre;
				list[next]=next;
				if(first==i) first=next;
			}
			void query(int k)//访问第k个节点的值
			{
				int p=first;
				for(int i=1;i<k;i++)
				{
					p=list[p].next;
				}
				return list[p].data;
			}
		实现二:
			struct node
			{
				node* next,pre;
				int data;
			};
			
	3.队列:
	4.栈:
	5.堆:
		大根堆与小根堆:
			大根堆:top与pop为最大值
			小根堆:top与pop为最小值
		操作:
			push();//加入
			pop();//弹出最大值
			top();//访问最大值
			size();//大小
		STL实现:
			大根堆:
				#include <queue>
				priority_queue<int> heap;//声明堆(大根堆)
				heap.push(x);//加入元素x O(log n)
				heap.size();//大小 O(1)
				heap.pop();//删除最大元素 O(log n)
				heap.top();//访问最大元素 O(1)
			小根堆:
				#include <queue>
				priority_queue<int> heap;//声明堆(小根堆)
				heap.push(-x);//加入元素x O(log n)
				heap.size();//大小 O(1)
				heap.pop();//删除最小元素 O(log n)
				-heap.top();//访问最小元素 O(1)
			
	6.哈希表:
	7.查并集:
		int r[MAX];//定义父节点
		for(int i=1;i<=n;++i)//每个节点的父节点初始化为自己
		{
			r[i]=i;
		}
		int getSet(int u)//查操作(查询根节点)
		{
			if(r[u] == u)
					return u;
			else
				return r[u]=getSet(r[u]);
		}
		r[getSet(u)]=getSet(v);//并操作,将含有u,v的集合合并
STL:

	queue:
		#include <queue>
		声明:queue<int/*数据类型*/> q;
		操作:	q.push(x);//入队
				q.size();//队列长度
				q.pop();//出队
				q.front();//队首元素
				q.empty();//是否为空
	stack:
		#include <stack>
		声明:stack<int/*数据类型*/> s;
		操作:	s.push(x);//入栈
				s.size();//栈长度
				s.pop();//出栈
				s.top();//栈顶元素
				s.empty();//是否为空
	priority_queue:
		#include <queue>
		声明:priority_queue<int> heap;//声明堆(大根堆)
		操作:	heap.push(x);//加入元素x O(log n)
				heap.size();//大小 O(1)
				heap.pop();//删除最大元素 O(log n)
				heap.top();//访问最大元素 O(1)
				heap.empty();//是否为空
	重载运算符operator:
		
	map(哈希表):
		//可当作下标亦可为无穷大或为负数的数组使用
		//访问或修改元素复杂度 O(log n),速度很慢
		#include <map>
		声明:map<int/*数组下标类型*/,double/*元素类型*/> ma;
			 map<string,int> smap;//下标类型可为string
					smap["xxxx"]=23333;
			 map<int,map<int,int> > dmap;//二维无穷大数组
		操作:
		
		
	algorithm:
		min(a,b)//两个参数类型必须一致(将小的类型转化为大的类型)
			int a;long long b;
			min((long long)a,b);
			min(1ll*a,b);
		max(a,b)
		swap(a,b)
		sort(a,b，cmp/*排序函数,可省略，默认从小到大*/)//a为排序首指针，b为排序尾后指针
			bool cmp(int a,int b)
			{
				return a>b;//返回a是否在b前面
			}
			选择，冒泡，插入排序O(n^2)
			快速(quick_sort())，归并(merge_sort(a,b)，堆(heap_sort())，sort O(nlog n)
			bogo-sort O(n*n!)
		reverse(a,b)//翻转，a为首指针，b为尾后指针
		unique(a,b)	//去重，a为首指针，b为尾后指针.去重前必须先排序
					//返回值为去重后的尾后指针，可用unique(a,b)-a获得去重后元素个数
		random shuffle(a,b)//随机打乱,a为首指针,b为尾后指针
		next_permutation()//当前排列的下一个，返回值代表能否产生下一个排列
		prev_permutation()//当前排列的上一个，返回值代表能否产生上一个排列
		max_element(a,b)//返回最大值的指针,a为首指针,b为尾后指针
		min_element(a,b)//返回最小值的指针,a为首指针,b为尾后指针
		
		
Day 2

A.M.
排序算法:
	//选择，冒泡，插入排序O(n^2)
	//快速(quick_sort())，归并(merge_sort(a,b)，堆(heap_sort())，sort O(nlog n)
	//bogo_sort O(n*n!)
	//计数排序O(m+n)
	1.计数排序(最大值m<=1000000)
	2.归并排序
		实现:
			#include<cstdio>
			using namespace std;
			int n,z[233],y[233];
			void merge_sort(int l,int r)
			{
				if (l==r) return;
				int m=(l+r)/2;
				merge_sort(l,m);
				merge_sort(m+1,r);
				int p1=l,p2=m+1;
				for (int a=l;a<=r;a++)
				{
					if (p1 > m)
						y[a] = z[p2++];
					else if (p2 > r)
						y[a] = z[p1++];
					else if (z[p1] < z[p2])
						y[a] = z[p1++];							
					else
						y[a] = z[p2];	
				}
				for (int a=l;a<=r;a++)
					z[a]=y[a];
			}
			int main()
			{
				scanf("%d",&n);
				for (int a=1;a<=n;a++)
					scanf("%d",&z[a]);
				merge_sort(1,n);
				for (int a=1;a<=n;a++)
					printf("%d\n",z[a]);
			}
		拓展————逆序对个数:
			#include<cstdio>
			using namespace std;
			int n,z[233],y[233];
			int merge_sort(int l,int r)
			{
				if (l==r) return 0;
				int m=(l+r)/2;
				int ans=merge_sort(l,m)+merge_sort(m+1,r);
				int p1=l,p2=m+1;
				for (int a=l;a<=r;a++)
				{
					if (p1 > m)
						y[a] = z[p2++];
					else if (p2 > r)
						y[a] = z[p1++];
					else if (z[p1] <= z[p2])
						y[a] = z[p1++];	
					else
					{
						y[a] = z[p2++];
						ans += m-p1+1;
					}
				}
				for (int a=l;a<=r;a++)
					z[a]=y[a];
				return ans;
			}
			int main()
			{
				scanf("%d",&n);
				for (int a=1;a<=n;a++)
					scanf("%d",&z[a]);
				printf("%d\n",merge_sort(1,n));
			}
			
			
P.M.	
	3.贪心算法：
		//n=2时推出的式子可应用到n>=3的任何情况
	4.前缀和/积
		s[i]=a[1]+a[2]+……+a[i];//前缀和
		a[l]+a[l+1]+……+a[r-1]+a[r]=s[r]-s[l-1];
	5.快速幂
		O(log y)
		(A+B)modb=(Amodb+Bmodb)modb
		(A×B)mod b = ((A mod b) × (B mod b)) mod b(A×B)mod b=((A mod b)×(B mod b))mod b
	6.二分查找（存在单调性）

	位运算:
		&按位与
			x%2 <==> x&1
		|按位或
		^按位异或
		<<左移
			x<<y <==> x=x*2^y
			1<<x <==> 2^x
		>>右移
			x>>y <==> x=x/2^y
	运算速度:
		//速度自上至下递减	
		&& & | ^ << >> ||
		<= >= != ==	+ -
		*
		/ %
		sqrt()

	7.st表(求一段区间最大值或最小值)
		//本质上为二维数组
		f[i][j]=max(a[i],a[i+1],……,a[i+2^(j-1)])//从a[i]到a[i+2^(j-1]的最大值
		//递推关系式
		f[i][0]=a[i]
		f[i][j]=max(f[i][j-1],f[i+2^(j-1)][j-1]
		//无法直接查到的用两个互有重叠的区间覆盖该区间来查找
		//下段代码用于当区间长度为r-l+1时所使用的指数x
		for (int i=1;(1<<i) <= n;i++)
			for (int j=(1<<i); j < (1<<(i+1)); j++)
				er[j] = i;
		int l,r;
		scanf("%d%d",&l,&r);
		int x=er[r-l+1];
		printf("%d\n",max(f[l][x],f[r-(1<<x)+1][x]));
		
		
Day 3

A.M.

图：
	图的表示
		邻接矩阵:
			g[u][v]=m;//表示从u到v的边的权值
			g[u][v]=g[v][u];//无向图
		邻接表:
			//使用链表保存以u为起点的所有边，再使用数组保存所有链表头指针
			#include <cstdio>
			#include <cstring>
			struct Edge 
			{
				int to, value;
				int next;
			};
			const int maxn = 10003; // 最大的点数
			const int maxm = 100003; // 最大的边数
			int n, m;
			int head[maxn], total;
			Edge edges[maxm];
			void addEdge(int u, int v, int w) 
			{  
				// 加一条从u到v的边
				edges[total].to = v;
				edges[total].value = w;
				edges[total].next = head[u];
				head[u] = total;
				total++;
			}
			int main() 
			{
				memset(head, 0, sizeof(head));
				total = 1;
				scanf("%d%d", &n, &m);
				for (int i = 0; i < m; ++i) 
				{
					int u, v, w;
					scanf("%d%d%d", &u, &v, &w);
					addEdge(u, v, w);
					addEdge(v, u, w);
				}
			}

		边数组:
			//把每条边的起点终点长度开个数组顺次存下来.	
	概念
		度数:链接到某顶点的边的数量
		入度/出度:
		连通图/强连通图:无向图/有向图任意顶点对可到达
		树:有m个顶点,m-1条边的图
	七桥问题:
		欧拉: 七桥问题无解
		回路:一个起点和终点相同的边序列
		欧拉回路:从一个点出发每边只走一遍就能把所有路线都走过的回路
			一个无向图存在欧拉回路的充分必要条件: 每个点的度数都为偶数,且连通.
			一个有向图存在欧拉回路的充分必要条件:每个点的入度等于出度,且强连通
		欧拉路径:从一个点出发每边只走一遍就能把所有路线都走过(起点和终点不一定相同)
		哈密顿回路:从一个点出发经过所有顶点恰好一次就能把所有路线都走过的回路
			充要条件不存在
	基本算法:
		1.最短路 Floyd/ Dijkstra(+heap)/ Bellman-Ford(SPFA)
			两种最短路:
				单源最短路:已知一个起点,求它到所有点的最短路长度.
				多源最短路:对每个顶点都跑上面的东西
			1.1.Dijkstra算法
				红色set:确定已知的最短路
				绿色set:从红色set可一步到达的
				过程:每次将绿色set中最短的加入红色set,并从这个点更新绿色set
				
				这是最靠谱的无负权图单源最短路算法.
				假设: 一些点的最短路已经算出来了,另一些还没算.
				开始的时候只有起点的最短路径长度已知.
				现在有了一个"从已知距离点一步能到"的点集. 每次选这个集合里距
				离最小的,扔进已知点集.
				循环O(n^2)
				代码实现:
					#include <cstdio>
					#include <cstring>
					#include <algorithm>
					using namespace std;
					int g[maxn][maxn], n, m;
					int distance[maxn], status[maxn];
					//  status: 0-empty 1-in green 2-in red
					void dijkstra(int start_point) 
					{
						memset(status, 0, sizeof(status));
						memset(distance, 0x3f, sizeof(distance));
						distance[start_point] = 0;
						status[start_point] = 1;
						for (int ti = 0; ti < n; ++ti) 
						{
							//  select v
							int vertex_to_pick = -1;
							for (int i = 1; i <= n; ++i) 
							{
								if (status[i] == 1) 
								{
									if (vertex_to_pick == -1 || distance[i] < distance[vertex_to_pick]) 
									{
										vertex_to_pick = i;
									}
								}
							}
							if (vertex_to_pick == -1) 
							{
								break;
							}
							//  add to red set
							status[vertex_to_pick] = 2;
							//  update distance from this vertex
							for (int i = 1; i <= n; ++i) 
							{
								if (status[i] == 0 || status[i] == 1) 
								{
									if (g[vertex_to_pick][i] != -1) 
									{
										status[i] = 1;
										distance[i] = min(distance[i], distance[vertex_to_pick] + g[vertex_to_pick][i]);
									}
								}
							}
						}
					}
					int main() 
					{
						memset(g, -1, sizeof(g));
						scanf("%d%d", &n, &m);
						for (int i = 0; i < m; ++i) 
						{
							int u, v, w;
							scanf("%d%d%d", &u, &v, &w);
							g[u][v] = g[v][u] = w;
						}
						dijkstra(1);
					}
					
					
					
				heap优化:
					时间复杂度可以进一步优化.把" 一步能到点集" 扔进一个堆里.
					O((n + m) *logm).
			1.2.Bellman-Ford(SPFA)算法
				/sipufa/
				江湖传说—SPFA 的复杂度是 O(n) 的!!!
				还是从起点开始. 把所有可能到且比原来更近的点全都扔进队列里.
				然后接着更新,直到队列空了.
				写的时候请注意: 你需要循环队列, 你需要判断这个点是否已经在队里
				了.
				可能被卡成 O(n^2). 实际上一般效果没有 Dijkstra 好.
				它比 Dijkstra 的优势在于, 它可以有负边权 (不能有负环)
				#include <cstdio>
				#include <cstring>
				using namespace std;
				struct Edge
				{
					int to, value;
					int next;
				};
				const int maxn = 10003; // zui da de dian shu
				const int maxm = 100003; // zui da de bian shu
				int n, m;
				int head[maxn], total;
				Edge edges[maxm];
				void addEdge(int u, int v, int w) 
				{  // jia yi tiao cong u dao v de bian
					edges[total].to = v;
					edges[total].value = w;
					edges[total].next = head[u];
					head[u] = total;
					total++;
				}
				int distance[maxn], in_queue[maxn];
				void SPFA(int start_point) 
				{
					queue<int> que;
					memset(distance, 0x3f, sizeof(distance));
					memset(in_queue, 0, sizeof(in_queue));
					distance[start_point] = 0;
					que.push(start_point);
					while (!que.empty()) 
					{
						int u = que.front(); que.pop();
						in_queue[u] = false;
						for (int i = head[u]; i; i = edges[i].next) 
						{
							int v = edges[i].to;
							if (distance[v] > distance[u] + edges[i].value) 
							{
								distance[v] = distance[u] + edges[i].value; 
								if (!in_queue[v])
								{
									in_queue[v] = true;
									que.push(v);
								}
							}
						}
					}
				}
				int main() 
				{
					memset(head, 0, sizeof(head));
					total = 1;
					scanf("%d%d", &n, &m);
					for (int i = 0; i < m; ++i) 
					{
						int u, v, w;
						scanf("%d%d%d", &u, &v, &w);
						addEdge(u, v, w);
						addEdge(v, u, w);
					}
				}

			1.3.Floyd算法
				//最短路的一部分一定是最短路
				这是一个” 拼凑” 最短路的算法.
				每条最短路都是由若干条最短路组成的.
				那么我们一段一段地将它拼凑起来.
				首先连接以 1 号点为断点的最短路. 然后是 2 号点, ….
				实现(核心代码):
					for(int k=1;k <= n;++k)
						for(int i=1;i <= n;++i)
							for(int j=1;j <= n;++j)
								dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		2.最小生成树 Prim/ Kruskal
			生成树:一个 n 个顶点的连通无向图, 选 n − 1 条边出来, 使得新图中n个顶点依然连通.
			最小生成树:边权和最小的生成树.
			最大生成树:边权和最大的生成树.
			性质:
				对于最小生成树: 两点之间路径上的最大边权最小.
				对于最大生成树: 两点之间路径上的最小边权最大.
			2.1.Kruskal算法O(m log m)
				//把所有边从小到大排序.依次试着加进新图. 如果加进去之后不是树了就算了.
				#include <cstdio>
				#include <algorithm>
				using namespace std;
				struct Edge 
				{
					int u, v, w;
				};
				bool operator<(Edge a, Edge b) 
				{
					return a.w < b.w;
				}
				const int maxm = 100003;
				int n, m, r[maxm];
				Edge e[maxm];
				int getSet(int u) 
				{
					return r[u] == u ? u : (r[u] = getSet(r[u]));
				}
				int main()   
				{
					scanf("%d%d",&n,&m);
					for (int i = 0; i < m; ++i) 
					{
						scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
					}
					for (int i = 1; i <= n; ++i) 
					{
						r[i] = i;
					}
					sort(e, e + m);
					//  minimal spanning tree
					int mst_size = 0;
					for (int i = 0; i < m; ++i) 
					{
						if (getSet(e[i].u) != getSet(e[i].v)) 
						{
							mst_size += e[i].w;
							r[getSet(e[i].u)] = getSet(e[i].v);
						}
					}
				}
			2.2.Prim算法
				/*	
				*	同Dijkstra
				*	唯一的不同是” 最小” 的不是最短路长度, 
				*	而是连接已选和未选点集的边的长度	
				*/	
				//标程未成品
				#include <cstdio>
				#include <cstring>
				#include <algorithm>
				using namespace std;
				int g[maxn][maxn], n, m;
				int distance[maxn], status[maxn],book[maxn];
				//  status: 0-empty 1-in green 2-in red
				void dijkstra(int start_point) 
				{
					memset(status, 0, sizeof(status));
					memset(distance, 0x3f, sizeof(distance));
					distance[start_point] = 0;
					status[start_point] = 1;
					for (int ti = 0; ti < n; ++ti) 
					{
						//  select v
						int vertex_to_pick = -1;
						for (int i = 1; i <= n; ++i) 
						{
							if (status[i] == 1) 
							{
								if (vertex_to_pick == -1 || g[i][ti+1] < g[vertex_to_pick][ti+1]) 
								{
									vertex_to_pick = i;
								}
							}
						}
						if (vertex_to_pick == -1) 
						{
							break;
						}
						//  add to red set
						status[vertex_to_pick] = 2;
						//  update distance from this vertex
						for (int i = 1; i <= n; ++i) 
						{
							if (status[i] == 0 || status[i] == 1) 
							{
								if (g[vertex_to_pick][i] != -1) 
								{
									status[i] = 1;
									distance[i] = min(distance[i], distance[vertex_to_pick] + g[vertex_to_pick][i]);
								}
							}
						}
					}
				}
				int main() 
				{
					memset(g, -1, sizeof(g));
					scanf("%d%d", &n, &m);
					for (int i = 0; i < m; ++i) 
					{
						int u, v, w;
						scanf("%d%d%d", &u, &v, &w);
						g[u][v] = g[v][u] = w;
					}
					dijkstra(1);
				}	
		3.拓扑排序(topoSort)
			把有向无环图 (DAG) 转成序列:
				如果存在一条边 e(u; v), 那么 u 必须排在 v 的前面
			方法:
				统计入度.
				找出所有入度为零的点.
				把这些点从图里删掉, 更新其它点的入度.重复
		4.找负环 DFS/ SPFA/ Floyd
			4.1.SPFA 找负环 一个点被更新超过 n 次, 肯定有负环
			4.2.DFS版SPFA 找负环 一个点是否自己更新自己
			4.3.Floyd 找负环 跑一遍, 再跑一遍, 看是否有变化
		5.找强连通分量/求割顶/求割边/点双/边双 Tarjan/ Kosaraju
			
Day 4

A.M.

搜索:			
	深度优先搜索DFS:
		运行次数:
			f(n) 调用了 n 次 f(n − 1) T(f(n)) = n!
			f(n) 调用了 2 次 f(n − 1) T(f(n)) = 2^n
		估计是否超时:
			把题目中的 n; m; : : : 代入你算的式子, 得出一个值.
			参考值:
				< 107 基本稳过.
				[10^7,10^8) 看出题人的姿势水平.
				[10^8,10^9] 看脸.
				> 109 去买彩票吧.
	
P.M.
	
	宽度优先搜索BFS:
	


	搜索优化:
		1.位运算
			<< 左移 (乘 2)
			>> 右移 (整除 2)
			& 按位与
			| 按位或
			̃ 按位取反
			̂ 异或
		2.卡时
		3.随机化	
			#include <cstdlib>
			//随机先后
			if(rand() & 1)
			{}
			else
			{}
			//随机数据
			
		4.剪枝	
			4.1.可行性剪枝:
				如果当前状态已经不可行, 那么不搜索它
			4.2.最优性剪枝:
				如果当前状态不可能达到最优效果, 则放弃它
			4.3.启发式搜索
				每次搜索要 for (int i = 0; i < n; ++ i) { …}
				对 n 个子状态进行估计, 先搜更有可能优的. (配合可行和最优性剪枝)
			e.g.极大团搜索	
				//团的定义为一个无向图的完全子图.
			
			
Day 5

A.M.
动态规划：
	动态规划（Dynamic Programming）是是运筹学的一个分支，是求解决策过程最优化的数学方法。
	/*	
		动态规划被用于解决多阶段最优化决策问题。它的基本思路是将待解决的问题划分成
		多个阶段，每个阶段可能存在多种不同的状态。
		如果划分阶段后的问题满足最优子结构，则可以用动态规划算法一个阶段一个阶段，
		一个状态一个状态地解决问题的所有子问题，继而解决原问题。
	*/
	阶段:
		阶段的划分是人为的。但是必须满足在一个阶段的任意状态做出任何决策后，得到的
		新状态都属于之后的阶段。（甚至不能在原阶段停留）
		不过实际问题中，有的时候阶段并不是线性的，有的时候你很难描述阶段，但是实际
		上阶段只是提供了一个解决问题的顺序和设计状态的思路，设计出合理高效的状态才
		是解决问题的关键。即：阶段的最大作用是辅助状态设计。
		描述一个状态描述一个状态用了几个“某”字，这个状态就是几维的。
	决策:
		决策是一个集合。不同的状态可能有不同的决策集合。但是同一个状态一定有相同的决策集合。
	转移:
		转移用来描述两个子问题之间的关系，A子问题对应的状态进行决策C能到转化为B子问题，称为A→B有C转移。
	最优解:
		不能被优化的解叫最优解，一个问题的最优解不一定唯一，但是最优解的目标值唯一。（废话）
	最优子结构:
		能动态规划解决的问题必须满足——任何一个子问题的最优解，做出第一步决策之后，
		剩下的决策集合仍然是转移到的子问题的最优解。这一条件叫做最优子结构。
		这个条件也有等价描述如——
			每个子问题的解与转移到它所经历的决策互不影响。（无后效性）
	//动规中不存在最优决策，动规的思想是，虽然我不知道我接下来该怎么走，但我选用当
	前状态的最优解一定不会比不选用当前最优解差。
	1.记忆化搜索
		利用子问题的思想，通过枚举到某个状态的前一步决策是什么，递归地解决前一个子问题，再求出当前子问题的最优解。
		开一个数组记录每一个子问题的最优解，如果在对子问题求解的过程中，发现之前已经求过了该问题的最优解，则直接返回之前求过的答案！
		由于备忘录保证了不会重复求解子问题的性质，因此没有必要按顺序求解子问题，你可以按照任何顺序决定开始递归的状态。
		e.g.1
			给一个N行M列的表格，每个格子里有一个整数。你从第一行选一个格子进入，
			之后每一步只能向左下，正下或右下走，不能走到表格之外。走到最后一行时
			结束，你的得分为你走过的每一个格子上数字之和，要求最大化你的得分。
				int Solve (int x,int y) //解决子问题：到达(x,y)的最大得分
				{
					if (ans[x][y]!=-INF) return ans[x][y];
					if (x==n) return ans[x][y]=a[x][y]; //最小规模子问题
					int res=-INF; //将最大目标值预制为最小（负无穷）
					if (y>1) res=max(res,Solve(x+1,y-1)+a[x][y]);
					if (y<m) res=max(res,Solve(x+1,y+1)+a[x][y]);
					res=max(res,Solve(x+1,y)+a[x][y]);
					return ans[x][y]=res;
				}
		e.g.2
			众所周知，滑雪只能从海拔高处滑向海拔低处。告诉你一个平面区域的海拔，
			滑雪时每次可以向东南西北四个方向中海拔小于当前格子的格子滑一步，求最
			长的滑雪路线。
				int Solve (int x,int y) //解决子问题：从(x,y)出发的最长路线
				{
					if (ans[x][y]!=0) return ans[x][y];
					int res=1; //直接停止
					枚举四个方向的格子
						if (格子i海拔低于(x,y)) res=max(res,Solve(格子i)+1);
					return ans[x][y]=res;
				}
		1.1.记忆化搜索代码模式:
			int Solve(子问题)
			{
				if (子问题已求解) return 记录的结果;
				枚举每一个可以转移来的子问题 Solve(这些子问题),更新当前答案;
				记录答案;
				return 答案;
			}
			//主程序中
			枚举每一个子问题 Solve(该子问题);
		1.2.记忆化搜索优缺点分析
			优点：
				1. 普适性极强，所有满足最优子结构的问题都可以用记忆化搜索解决，不必要按阶段顺序求解，甚至不必要划分阶段
				2. 有的题目中一些小规模的子问题不会对最终答案有贡献，记忆化搜索不会对这些问题求解
				3. 思路直接，是正常的分析问题解决问题思路，不需要太多推导

			缺点：
				1. 在函数调用时需要消耗一定时间，而且递归层数过多可能造成栈空间超限
				2. 代码实现上稍微复杂一些（代码量大些）
				3. 程序结构复杂，不利于优化
	2.递推式搜索
		e.g.1
			给一个N行M列的表格，每个格子里有一个整数。你从第一行选一个格子进入，
			之后每一步只能向左下，正下或右下走，不能走到表格之外。走到最后一行时
			结束，你的得分为你走过的每一个格子上数字之和，要求最大化你的得分。
				将f[1~n][0~m+1]赋值为-INF
				for (int j=1;j<=m;j++) f[n][j]=a[n][j]; //求解极小子问题
				for (int i=n-1;i>=1;i--) 
					for (int j=1;j<=m;j++) 
						f[i][j]=a[i][j]+max(f[i+1][j-1],f[i+1][j],f[i+1][j+1]);
				for (int j=1;j<=m;j++) ans=max(ans,f[1][j]);
			e.g.2
				给一个有向无环图（DAG），每个点有点权，每条弧有边权，一些点被定义为出发点，
				一些点被定义为结束点。一个点可以既是出发点又是结束点，也可以都不是。
				一条链（弧要同向）的价值是这条链上所有弧与点的权值之和（包括起止点）。
				求DAG中所有从出发点开始到结束点为止的链中，价值最大的链

		2.1.递推式DP优缺点分析
			优点：
				1. 代码简短，运行常数小
				2. 方便概括，程序结构清晰，易于发现优化

			缺点：
				1.  需要一定的推导，有一定的思维难度
				2.  每一个状态都会被求解，无法排除无效状态
		2.2.什么时候用递推式DP
			1） 明确了是动态规划问题
			2） 拓扑序不需要程序求出，可以在分析问题时直接得出
			3） 按拓扑序DP时循环语句好控制
			4） 记忆化搜索明确复杂度不合适
			/*
			1）必满足，2）3）不满足且4）不满足时考虑重新设计状态或者直接记忆化搜索，
			2）3）不满足，且4）满足时考虑重新设计状态甚至换用DP以外的算法或结合数据结构解决
			*/

	3.动态规划的维数
		动态规划的维数分为2部分——状态的维数和转移的维数
		状态的维数指的是描述状态需要的变量数，在大多数情况下可以认为等于递推数组的维数。
		不过有的情况下比如f[i][j]，i=1~n，j=0~1，更倾向于1D而不是2D
		转移的维数指的是求出某个状态的递推值需要的进行的操作的数量级，大部分情况下等于每个状态对应决策的数量级
		比如前面的题目，走格子是2D0D（O(n^2)状态，O(1)转移）
		最大乘积是2D1D（O(nk)状态，O(n)转移）
		求出动态规划的维数对动态规划的优化有提示性作用，本节课不要求掌握，仅需了解概念




















		
			
			
