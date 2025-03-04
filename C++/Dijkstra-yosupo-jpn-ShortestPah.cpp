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
map<int,int> mp;
ll dijkstra(int s,int e){
   priority_queue<node,vector<node>,cmp> pq;
   dist[s]=0;
   pq.push({s,0});

   while(!pq.empty()){
      auto top = pq.top();
      pq.pop();

      if(top.val ==e)return top.cost;
      if (top.cost > dist[top.val]) continue;
      for(auto ch : adj[top.val]){
         ll nc =top.cost + ch.cost;
         if(dist[ch.val] > nc){
            dist[ch.val]=nc;
            mp[ch.val]=top.val;
            pq.push({ch.val,nc});
         } 
      }
   }
   return -1;
}

void solve() {
    int n,m,s,e;cin>>n>>m>>s>>e;
    adj.assign(n+1,vector<node>());
    //    p.assign(n+1,-1);
    for(int x = 0 ; x < m ; x++){
        int u,v,c;cin>>u>>v>>c;
        adj[u].push_back({v,c});
        // adj[v].push_back({u,c});
    }
    dist.assign(n+1,LLONG_MAX);
    ll c = dijkstra(s,e);
    if(c == -1) {
        cout << -1;
        return;
    }
    vector<pair<ll,ll>> vec;
    for(int v = e ; v!= s ; v = mp[v]){
        vec.push_back({mp[v],v});
    }
    reverse(vec.begin(),vec.end());
    cout << c<<" " <<vec.size()<<"\n";
    for(auto [u,v]:vec){
        cout << u << " " << v << "\n";
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

