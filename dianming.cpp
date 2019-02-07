#include <iostream>
#include <fstream>
#include <ctime>
int main()
{
	int t=time(NULL);
	t%=50;
	t+=1;
	switch(t)
	{
		case 4:t=8;break;
		case 39:t=8;break;
		default:;
	}
	cout<<t<<endl;
	system("pause");
	return 0;
}
