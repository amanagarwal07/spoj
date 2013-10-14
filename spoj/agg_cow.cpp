#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int main()
{
	int check(const vector<int>&,int,int);
	int t,stalls,cows,r,l,x,mid,b;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> c;
		scanf("%d %d",&stalls,&cows);
		while(stalls--)
		{
			scanf("%d",&x);
			c.push_back(x);
		}
		sort(all(c));
		l=1;
		r=*(c.end()-1)-c[0]+1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			b=check(c,mid,cows);
			if(b==1)
				l=mid+1;
			else
				r=mid-1;
		}
		cout<<l-1<<endl;
		c.clear();
	}
}
int check(const vector<int>& v,int mid,int cows)
{
	int c=1,pre=v[0];
	tr(v,it)
	{
		if(*it-pre>=mid)
		{
			c++;
			pre=*it;
		}
	}
	if(c>=cows)
		return 1;
	return 0;
}
