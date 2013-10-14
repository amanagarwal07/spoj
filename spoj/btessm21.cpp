/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : btessm21.cpp
* Creation Date : 15-02-2013
* Last Modified : Friday 15 February 2013 01:18:57 AM IST
* Created By :  Aman Agarwal
_._._._._._._._._._._._._._._._._._._._._.*/
                                   
#include <iostream>
#include <cmath>
#include <cstdio>
#include<climits>
using namespace std;
int main()
{
	int maxx(int,int,int);
	int arr[101][101],test,h,w,ans[101][101],i,j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&h);
		scanf("%d",&w);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				scanf("%d",&arr[i][j]);
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(i==0)
					ans[i][j]=arr[i][j];
				else if(j==0)
					ans[i][j]=arr[i][j]+maxx(ans[i-1][j],ans[i-1][j+1],-1);
				else if(j==w-1)
					ans[i][j]=arr[i][j]+maxx(ans[i-1][j],ans[i-1][j-1],-1);
				else
					ans[i][j]=arr[i][j]+maxx(ans[i-1][j],ans[i-1][j-1],ans[i-1][j+1]);
			}
		}
		int maxm=INT_MIN;
		for(i=0;i<w;i++)
			if(ans[h-1][i]>maxm)
				maxm=ans[h-1][i];
		printf("%d\n",maxm);
	}
	return 0;
}
int maxx(int a,int b,int c)
{
	return a>=b?(c>=a?c:a):(c>=b?c:b);
}
