#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<algorithm>
using namespace std;
int a[100005],n;
void Qsort(int l,int r)   //避免撞关键字，开头用了大写 
{
    int i,j,mid;
    i=l;j=r;
    srand(time(0));//用随机函数来生成关键字
    mid=a[l+rand()%(r-l+1)];
    do
    {
        while(a[i]<mid)i++;
        while(a[j]>mid)j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    if(l<j) Qsort(l,j);
    if(i<r) Qsort(i,r);
}
int main()//主程序 
{
    //freopen("Qsort.in","r",stdin);
    //freopen("Qsort.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    Qsort(1,n);
    for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
    getchar();
    return 0;
}