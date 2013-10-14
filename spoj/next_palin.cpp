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
	string ans="";
	string s="1";
	int n,l,flag=0,mid,back,front,eq=0,i;
	cin>>n;
	while(1)
	{
		cout<<s<<endl;
		ans=ans+s;
		if(ans.length()>n)
			break;
		flag=0;
		eq=0;
		l=s.length();
		if(l&1)
		{
			mid=l/2;
			back=mid-1;
			front=mid+1;
		}
		else
		{
			mid=(l/2)-1;
			back=mid;
			front=mid+1;
		}
		int b=back,f=front;
		for(;back>=0,front<l;back--,front++)
		{
			if((int)(s[back])<(int)(s[front]))
				flag=1;
			else if(s[back]==s[front])
				continue;
			else break;
		}
		back=b;
		front=f;
		if(flag==0)
		{
			for(;back>=0,front<l;back--,front++)
			{
				if((int)(s[back])!=(int)(s[front]))
				{
					eq=0;
					break;
				}
				eq=1;
			}
		}
		if(flag==1 || eq==1)
		{
			int ff=0;
			int x=(int)(s[mid])-48;
			if(x==9)
			{
				s[mid]='0';
				for(i=mid-1;i>=0;i--)
				{
					x=(int)(s[i])-48;
					if(x==9)
						s[i]='0';
					else
					{
							s[i]=(int)(s[i])+(int)(1);
							break;
					}
				}
				for(i=f;i<l;i++)
					s[i]=s[b--];
				if(s[0]=='0')
				{
					rintf("1");
					s[i-1]='1';
				}
			}
			else
			{
				s[mid]=(int)(s[mid])+(int)(1);
				for(i=f;i<l;i++)
					s[i]=s[b--];
			}
		}
		else
		{
			for(i=f;i<l;i++)
				s[i]=s[b--];
		}
	}
	cout<<ans<<endl;
	cout<<ans[n]<<endl;
	return 0;
}
