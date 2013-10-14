#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<cstring>
#include<set>
#include<map>
typedef long long int LL;
typedef unsigned long long int ULL;
#define sf(a) scanf("%d",&a);
#define pf(a) printf("%d",a);
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int main()
{
	string s,tmp;
	char ss[100002];
	scanf("%s",ss);
	s=ss;
	tmp=s;
	int i,len=s.size(),ans=0,t=0;
	for(i=0;i<len;i++)
	{
		string x=s.substr(i,len-i)+s.substr(0,i);
		if(x<tmp)
		{
			tmp=x;
			t=ans;
		}
		ans++;
	}
	cout<<t<<endl;
	return 0;
}
