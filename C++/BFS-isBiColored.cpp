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

const int N =1e5+5 , M =2e5+5 ,OO=0x3f3f3f3f;
int c1 = 0 , c2 = 1 , c3 = 3;
int n,m,u,v;
vector<int> adj[N];
int color[N];

bool bfs(int src){
   memset(color,c1,sizeof color);
   color[src] = c2;
   queue<int> q;
   q.push(src);
   while(!q.empty()){
      int u = q.front();
      q.pop();
      for(int v : adj[u]){
         if(color[v] == c1){
            color[v] = (color[u] == c2 ? c3:c2);
            q.push(v);
         }
         else if(color[v] == color[u])
            return false;
      }
   }
   return true;
}


void solve() {
   cin>>n>>m;
   for(int x =0 ;x <m ; x++){
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   puts(bfs(0) ? "YES":"NO");
}
    
int main() {
   FastIO;
#ifdef USACO
   setIO("lineup");
#endif
   solve();

}
