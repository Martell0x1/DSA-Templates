#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;
struct node{
   ll val,cost;
};
struct cmp{
   bool operator()(node&a ,node&b){
      return a.cost > b.cost;
   }
};
vector<vector<node>> adj;
vector<ll> dist;
void dijkstra(int s,int e){
   priority_queue<node,vector<node>,cmp> pq;
   dist[s]=0;
   pq.push({s,0});

   while(!pq.empty()){
      auto top = pq.top();
      pq.pop();

      if (top.cost > dist[top.val]) continue;
      // if(top.val ==e)return;
      for(auto ch : adj[top.val]){
         ll nc =top.cost + ch.cost;
         if(dist[ch.val] > nc){
            dist[ch.val]=nc;
            pq.push({ch.val,nc});
         } 
      }
   }
}

void solve() {
   int n,m;cin>>n>>m;
   adj.assign(n+1,vector<node>());
   for(int x = 0 ; x < m ; x++){
      int u,v,c;cin>>u>>v>>c;
      adj[u].push_back({v,c});
      // adj[v].push_back({u,c});
   }
   dist.assign(n+1,LLONG_MAX);
   dijkstra(1,n);
   for(int x = 1 ; x <= n ; x++){
      cout << dist[x] <<" ";
   }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
/*
9 9
1 2 4
1 3 5
2 5 2
2 4 2
5 8 6
8 9 5
9 7 8
3 6 8
4 9 12

*/
