#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define ULL unsigned long long
int phi(int n)
{
	int result = n;
	int i;
	for(i=2;i*i <= n;i++) 
	{ 
		if (n % i == 0) 
			result -= result / i; 
		while (n % i == 0) 
			n /= i; 
	} 
	if (n > 1)
		result -= result / n; 
	return result; 
}
int main()
{
	vector<long long> ans(1000002,0);
	int t,num;
	for(int i=1;i<=1000000;i++)
	{
		ans[i]=ans[i-1]+i*phi(i);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		ULL res=((1+ans[num])*num)/2;
		printf("%llu\n",res);
	}
	return 0;
}


