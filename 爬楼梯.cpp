#include <iostream>
using namespace std;
int f(int n);
int main()
{
    int n;
    cin>>n;
    cout<<f(n);
    getchar();getchar();
    return 0;
}
int f(int n)
{
    if(n<=2)
        return n;
    else
        return f(n-1)+f(n-2);
}