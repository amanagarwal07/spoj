#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include<stack>
#include<vector>
#include<climits>
#include<cstring>
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
typedef struct ptr
{
	LL width,height,depth;
	LL area,theight;
}stud;
bool compare(const stud &a,const stud &b)
{
	return a.area>b.area;
}
int min (int x, int y)
{ 
	return (x < y)? x : y; 
}
int max (int x, int y)
{ 
	return (x > y)? x : y; 
}
int main()
{
	int n,t=0;
	LL w,d,h;
	while(1)
	{
		vector<stud> arr(200);
		t=0;
		scanf("%d",&n);
		if(n==0)
			return 0;
		while(n--)
		{
			cin>>h>>w>>d;
			arr[t].height=h;
			arr[t].width=min(w,d);
			arr[t].depth=max(w,d);
			arr[t].area=arr[t].width*arr[t].depth;
			t++;
			arr[t].height=w;
			arr[t].width=min(h,d);
			arr[t].depth=max(h,d);
			arr[t].area=arr[t].width*arr[t].depth;
			t++;
			arr[t].height=d;
			arr[t].width=min(w,h);
			arr[t].depth=max(w,h);
			arr[t].area=arr[t].width*arr[t].depth;
			t++;
		}
		sort(all(arr),compare);
		LL max=-1;
		vector<stud> h(200);
		for(int i=0;i<200;i++)
			h[i].height=0;
		h[0].width=arr[0].width;
		h[0].depth=arr[0].depth;
		h[0].height=arr[0].height;
		max=arr[0].height;
		for(int i=1;i<arr.size();i++)
		{
			for(int j=0;j<h.size();j++)
			{
				if(arr[i].width<h[j].width && arr[i].depth<h[j].depth)
				{
					if(h[j].height+arr[i].height > h[i].height)
					{
						h[i].height=arr[i].height+h[j].height;
						h[i].width=arr[i].width;
						h[i].depth=arr[i].depth;
						if(h[i].height>max)
							max=h[i].height;
					}
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
