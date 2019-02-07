#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue <long long> a;
long long js(long long n)
{
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			else
			{
				long long t=i^j;
				if(t>=((i<j)?i:j) && t<=((i>j)?i:j))
					++cnt;
			}
		}
	}
	return cnt;
}
int main()
{
	long long i=0,T,n;
	cin>>T;
	while(i<T)
	{
		cin>>n;
		a.push(js(n));
		i++;
	}
	i=0;
	while(!a.empty())
	{
		cout<<a.front()<<endl;
		a.pop();
	}
	return 0;
}
