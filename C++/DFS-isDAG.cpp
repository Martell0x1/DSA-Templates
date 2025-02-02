#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pv(v) for(auto x : v) cout << x << " ";
#define all(v) v.begin(), v.end()

typedef string STR;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<long long> vll;
typedef map<ll , ll> mpll;
using namespace std;

const int N_=10e5+6,M=2*10e5+6;
const int NOT_VISITED = 0 , IN_PROGRESS = 1 , VISITED = 2;
int m,n,u,v;
vector<int> adj[N_];
int vis[N_];

bool isDAG(int u)
{
   vis[u]=IN_PROGRESS;
   for(int v : adj[u])
   {
      if(vis[v] == NOT_VISITED)
      {
         if(!isDAG(v)) return false;
      }
      else if(vis[v] == IN_PROGRESS) return false;
   }
   vis[u]=VISITED;
   return true;
}
int main()
{
   // #define USACO;
   cin>>n>>m;
   int s;
   // set<pair<int,int>> duplicatedEdges;
   for(int x = 0 ; x < m; x++)
   {
      cin >> u >> v;
      // if(duplicatedEdges.count({u,v}) || duplicatedEdges.count({v,u})) continue;
      // duplicatedEdges.insert({u,v});
      adj[u].push_back(v);
      // adj[v].push_back(u);
      s=u;
   }
   // check all connected components;
   puts(isDAG(s) ? "DAG":"NOT DAG");
}
