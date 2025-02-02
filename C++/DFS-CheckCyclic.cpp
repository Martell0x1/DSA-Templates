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

const int N_=1e5+5,M=2e5+5;
int n,m,u,v;
vector<int> adj[N_];
bool vis[N_];
bool isCyclic(int n, int p)
{
   vis[n]=true;
   for(auto x : adj[n])
   {
      if(vis[x] && x != p) return true;
      else if(!vis[x])
      {
         if(isCyclic(x,n)) return true;
      }
   }
   return false;
}
int main()
{
   // #define USACO;
   cin>>n>>m;
   int s;
   set<pair<int,int>> duplicatedEdges; // prevent duplicated edges
   for(int x = 0 ; x < m; x++)
   {
      cin >> u >> v;
      if(duplicatedEdges.count({u,v}) || duplicatedEdges.count({v,u})) continue;
      duplicatedEdges.insert({u,v});
      adj[u].push_back(v);
      adj[v].push_back(u);
      s=u;
   }
   // check all connected components;
   for(int x = 1 ; x <= n ; x++)
   {
      if(!vis[x])
      {
         if(isCyclic(x,-1))
         {
            cout << "Cyclic!\n";
            return;
         }
      }
   }
   cout << "ACyclic";
}
