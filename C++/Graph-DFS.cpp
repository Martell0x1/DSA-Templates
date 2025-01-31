#include <bits/stdc++.h>
using namepace std;

int N2 =10e6,M=10e6;
int m,n,u,v;
vector<int> adj[N2];
bool vis[N2];
void dfs(int u)
{
   vis[u]=true;
   for(auto x : adj[u])
   {
      if(!vis[x])
         dfs(x);
   }
}

int main(){
	cin >> n>>m;
	for(int x = 0 ; x < n ; x){
		cin >>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(2);
}
