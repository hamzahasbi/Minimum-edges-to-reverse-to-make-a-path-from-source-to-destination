/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 27/01/2017 21:09:43
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
//inline lcm(int a,int b) {return a*b/__gcd(a,b);}
//inline gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}


using namespace std;

#define INF 1e6+5

int n,m;
unordered_map<int,vector<pair<int,int>>>graph;
bool visited[100005];
int dist[100005];
int parent[100005];

void dijkstra(int node)
{
	dist[node]=0;
	parent[node]=-1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(dist[node],node));
	while(!pq.empty())
	{
		int v=pq.top().second;
		pq.pop();
		
		if(visited[v]) continue;
		visited[v]=true;
		
		
		for(auto p:graph[v])
		if(dist[p.first] > dist[v] + p.second){
				dist[p.first] = dist[v] + p.second;
				parent[p.first]=v;
				pq.push({dist[p.first],p.first});
			}
	}
}
main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill(visited, visited+100005, false);
	fill(dist, dist+100005, INF);
	fill(parent, parent+100005, -1);
	graph.clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		//assuming that the edge goes from A to B
		graph[a].push_back({b,0});
		//making a reverse edge with cost of 1 to count how many edges we need to add to have a path from a 
		//source to a specific destination ...so if it already exists we have cost =0
		graph[b].push_back({a,1});
	}
	
	int source ,destination;
	scanf("%d%d",&source,&destination);
	dijkstra(source);
	if(dist[destination]==INF) cout<<"You can't reach that node even with reversed edges"<<endl;
	else cout<<dist[destination]<<endl;
 	return 0;
}
