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
#define pf(a) printf("%d\n",a);
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
int main()
{
	int t,g,z,i;
	string s;
	double n, ip,x;
	for(scanf("%d", &t); t; --t)
	{
		int flag=0,cnt=0;
		z=0;
		cin>>s;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='.')
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"1\n";
			continue;
		}
		for(int k=i+1;s[k]!='\0';k++)
			cnt++;
		if(cnt==1)
			s=s+"000";
		else if(cnt==2)
			s=s+"00";
		else if(cnt==3)
			s=s+'0';
		i++;
		for(;s[i]!='\0';i++)
			z=z*10+(int)(s[i]-'0');
		for(i=1;i<=10000;i++)
		{
			g=z*i;
			if(g%10000==0)
				break;
		}
		pf(i);
	}
	return 0;
}
