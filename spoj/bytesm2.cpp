#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<climits>
#include<set>
#include<map>
typedef long long int LL;
typedef unsigned long long int ULL;
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int max(int a,int b,int c)
{
	return a>=b?(c>=a?c:a):(c>=b?c:b);
}
int main()
{
	int max(int,int,int);
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
					ans[i][j]=arr[i][j]+max(ans[i-1][j],ans[i-1][j+1],-1);
				else if(j==w-1)
					ans[i][j]=arr[i][j]+max(ans[i-1][j],ans[i-1][j-1],-1);
				else
					ans[i][j]=arr[i][j]+max(ans[i-1][j],ans[i-1][j-1],ans[i-1][j+1]);
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
