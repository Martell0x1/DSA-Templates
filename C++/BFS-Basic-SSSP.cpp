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
int n,m,u,v;
vector<int> adj[N];
int dis[N];

void bfs(int src){
   memset(dis,OO,sizeof dis);
   dis[src]=0;
   queue<int> q;
   q.push(src);
   while(!q.empty()){
      int u = q.front();
      q.pop();
      for(auto x :adj[u]){
        if(dis[x] ==OO){
            q.push(x);
            dis[x] = dis[u]+1;
        }
      }
   }
}


void solve() {
   cin>>n>>m;
   for(int x =0 ;x <m ; x++){
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   bfs(0);
   for(int x = 0; x < n ;x++){
      cout << x <<" : "<<dis[x]<<"\n";
   }
}
    
int main() {
   FastIO;
#ifdef USACO
   setIO("lineup");
#endif
   solve();

}
