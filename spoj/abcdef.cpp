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
	int n,x,i=0,j=0,k;
	int s;
	long long ans=0;
	vector<int> v;
	vector<int> v1,v2;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&x);
		v.push_back(x);
		n--;
	}
	tr(v,it1)
	{
		tr(v,it2)
		{
			tr(v,it3)
			{
				s=(*it1)*(*it2)+(*it3);
				v1.push_back(s);
				if(*it3!=0)
				{
					s=((*it1)+(*it2))*(*it3);
					v2.push_back(s);
				}
			}
		}
	}
	sort(all(v1));
	sort(all(v2));
	int s1=0,s2=0;
	while(i<v1.size() && j<v2.size())
	{
		s1=s2=0;
		if(v1[i]==v2[j])
		{
			for(k=i;k<v1.size();k++)
			{
				if(v1[i]==v1[k])
					s1++;
				else
					break;
			}
			for(k=j;k<v2.size();k++)
			{
				if(v2[j]==v2[k])
					s2++;
				else
					break;
			}
			ans+=s1*s2;
			i+=s1;
			j+=s2;
		}
		else if(v1[i]<v2[j])
			i++;
		else
			j++;
	}
	

	cout<<ans<<endl;
	return 0;
}
