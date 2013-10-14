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
int ans=0;
int main()
{
	void func(string,int,int,int);
	int le,index=1,su;
	string s;
	while(1)
	{
		ans=0;
		cin>>s;
		le=s.length();
		if(s=="bye")
		exit(0);
		func(s,0,le,0);
		cout<<index<<". "<<ans<<endl;
		index++;
	}
	return 0;
}
void func(string s,int in,int le,int last_sum)
{
	int ps=0,i;
	for(i=in;i<le;i++)
	{
		ps+=(int)(s[i]-'0');
		if(ps>=last_sum)
		{
			if(i==le-1)
			{
				ans+=1;
				return;
			}
			else
				func(s,i+1,le,ps);
		}
	}
}
