/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : mst.cpp
_._._._._._._._._._._._._._._._._._._._._.*/
                                   
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
#define sf(a) read_int(a)
#define pf(a) printf("%d",a);
#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) //traversing a container..works for any type of container
#define present(container, element) (container.find(element) != container.end())    //used for set...return 1 if el is ps 0 otherwise
#define cpresent(container, element) (find(all(container),element) != container.end())  //same as present...but is for vectors
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define SET(v, val) memset(v, val, sizeof(v))
inline void read_int (int &n)
{
	n = 0;
	int i = getchar_unlocked();
	while (i < '0' || i > '9')
		i = getchar_unlocked();

	while (i >= '0' && i <= '9')
	{
		n = (n << 3) + (n << 1) + (i - '0');
		i = getchar_unlocked();
	}

}
#include<list>
struct Edge
{
	int src,dest,wt;
};
struct Graph
{
	int V,E;
	struct Edge *edge;
};
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
	return graph;
}
struct subset
{
	int parent,rank;
};
int find(struct subset subsets[], int i)
{
	cout<<i<<endl;
	    // find root and make root as parent of i (path compression)
	    if (subsets[i].parent != i)
		            subsets[i].parent = find(subsets, subsets[i].parent);
	     
	        return subsets[i].parent;
}
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->wt > b1->wt;
}
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and increment
	// its rank by one
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
void Kruskal(struct Graph* graph)
{
	int V = graph->V;
	int e = 0;  // An index variable, used for result[]
	int i = 0;  // An index variable, used for sorted edges

	int ans=0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	struct subset *subsets =
		(struct subset*) malloc( (V+1) * sizeof(struct subset) );

	// Create V subsets with single elements
	for (int v = 0; v <= V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	// Number of edges to be taken is equal to V-1
	while (e < V - 1)
	{
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if (x != y)
		{
			ans+=next_edge.wt;
			Union(subsets, x, y);
		}
	}
	cout<<ans<<endl;

	return;
}
int main()
{
	int V,E,x,y,wt;
	sf(V);
	sf(E);
	struct Graph *graph=createGraph(V,E);
	FOR(i,0,E)
	{
		sf(x);
		sf(y);
		sf(wt);
		graph->edge[i].src=x;
		graph->edge[i].dest=y;
		graph->edge[i].wt=wt;
	}
	Kruskal(graph);
	return 0;
}
