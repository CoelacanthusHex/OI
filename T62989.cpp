#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long s=0,r=1000000000;
	cin>>r;
	double a=sqrt(r),b=sqrt(2*r)/2;
	for(long long i=1;i<=b;i++)
		for(long long j=1;j<i;j++)
		{
			long long t=i*i+j*j;
			if(t<=r) s+=t;
		}
	for(long long i=b+1;i<=a;i++)
	{
		double c=b+(a-b)/2;
		double d=sqrt(r-c*c);
		double p=-i+2*b,q=(-c/d)*i+c*c/d+d;
		for(long long j=1;j<q && j<p;j++)
		{
			long long t=i*i+j*j;
			if(t<=r) s+=t;
		}
	}
		
	s*=2;
	for(long long i=1;i<=b;i++)
		s+=2*i*i;
	for(long long i=1;i<=a;i++)
		s+=i*i;
	s*=4;
	s%=1000000007;
	cout<<s;
	return 0;
} 
