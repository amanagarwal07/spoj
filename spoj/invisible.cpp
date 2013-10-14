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
	int t,arr[1000001],i,n,x;
	scanf("%d",&t);
	arr[3]=3;
	arr[4]=3;
	arr[5]=4;
	for(i=6;i<=1000000;i++)
	{
		x=ceil((float)i/2.0);
		arr[i]=1+arr[x];
	}
	while(t--)
	{
		scanf("%d",&n);
		cout<<arr[n]<<endl;
	}
	return 0;
}
