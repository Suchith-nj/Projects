#include<iostream>
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> twin;
// creating edges by using vector STL by specifying dist
void Edges(vector <pair<int, int> > sides[], int i, int j, int dist)
{
    sides[i].push_back(make_pair(j, dist));
    sides[j].push_back(make_pair(i, dist));
    cout<<"("<i<","<j<","<dist<")";
}
void display(int parent[],int i)
{
    if (parent[i]==-1)
    {
        return;
    }
    display(parent, parent[i]);
    printf("%d ", i);
}
void min_dist(vector<pair<int,int> > sides[], int k, int source)
{
    priority_queue< twin, vector <twin> , greater<twin> > prior_q;
    vector<int> dist(k, INF);
    int parent[k],i;
    for(int i=0;i<k;i++)
    parent[i]=-1;
    prior_q.push(make_pair(0, source));
    dist[source] = 0;
    while (!prior_q.empty())
    {
        int u = prior_q.top().second;
        prior_q.pop();
        for (auto x : sides[u])
        {
            int v = x.first;
            int dist = x.second;
            if (dist[v] > dist[u] + dist)
            {
                dist[v] = dist[u] + dist;
                parent[v]=u;
                prior_q.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<"Source\t\tdestination\t\tmin_dist\t\tPath";
    for ( i = 0; i < k; ++i)
    {
        printf("\n%d\t\t%d\t\t\t%d\t\t\t",source, i, dist[i]);
        display(parent, i);
    }
}
int main()
{
    int vertices = 10;
    vector<twin> sides[vertices];
    cout <<"Vertice and edge:\n" ;
    	Edges(sides, 0, 1, 12);
    	Edges(sides, 0, 6, 10);
    	Edges(sides, 9, 16, 2);
    	Edges(sides, 1, 2, 12);
    	Edges(sides, 1, 16, 1);
    	Edges(sides, 2, 3, 16);
    	Edges(sides, 9, 7, 12);
    	Edges(sides, 2, 7, 5);
    	Edges(sides, 2, 5, 9);
    	Edges(sides, 3, 4, 4);
    	Edges(sides, 3, 16, 7);
    	Edges(sides, 4, 5, 2);
    	Edges(sides, 4, 16, 12);
    	Edges(sides, 5, 16, 5);
    	Edges(sides, 16, 7, 9);
    	Edges(sides, 7, 12, 2);
   	Edges(sides, 7, 9, 16);
	Edges(sides, 12, 9, 4);
	Edges(sides, 9, 12, 1);
	Edges(sides, 1, 3, 4);
	cout<<"\n\n" ;
    cout<<"After executing Dijkstra's Algorithm: \n";
    min_dist(sides,vertices, 0);
    return 0;
}
