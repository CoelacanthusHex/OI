#include <iostream>
#include <queue>
using namespace std;
queue <long long> a;
long long s=0;
long long sl(long long n,long long a1,long long a2,long long x,long long y)
{
	s=0;
	s+=a1*a1+a2*a2;
	for(int i=3;i<=n;i++)
	{
		long long t=y*a1+x*a2;
		s+=t*t;
		a1=a2;a2=t;
	}
	s%=1000000007;
	return s;
}
int main()
{
	int T;
	long long n,a1,a2,x,y;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n>>a1>>a2>>x>>y;
		a.push(sl(n,a1,a2,x,y));
	}
	while(!a.empty())
	{
		cout<<a.front()<<endl;
		a.pop();
	}
	return 0;
}
