#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int t,a,arr[21],x,y,n;
	long long b;
	for(int i=1;i<=20;i++)
	{
		x=i%10;
		for(int j=2;;j++)
		{
			y=pow(i,j);
			if(y%10==x)
			{
				arr[i]=j-1;
				break;
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		scanf("%lld",&b);
		if(a==0 && b==0)
			cout<<"1"<<endl;
		else if(a==0)
		{
			printf("0\n");
			continue;
		}
		else if(b==0)
		{
			printf("1\n");
			continue;
		}
		else
		{
			x=b%arr[a];
			if(x==0)
				x=arr[a];
			y=pow(a,x);
			printf("%d\n",y%10);
		}
	}
	return 0;
}
