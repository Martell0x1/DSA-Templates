#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int64_t inf = 1e18;
struct node{
   ll val,ecost;
};
struct cmp{
   bool operator()(array<ll,3>&a,array<ll,3>&b){
      return a[0] > b[0];
   }
};
vector<vector<node>> adj;
vector<ll> ncost;
vector<vector<ll>>dist;

ll dijkstra(int s , int e){
   priority_queue<array<ll,3> , vector<array<ll,3>> , greater<>> pq;
   pq.push({0,s,ncost[s]});
   dist[s][ncost[s]] = 0;
   ll bn = inf;

   while(!pq.empty()){
      auto [d,v,k] = pq.top();
      pq.pop();

      if(v == e) {
         bn = min(dist[e][k],bn);
         continue;
      }
      if(dist[v][k] < d) continue;

      for(auto x : adj[v]){
         int nc = ncost[x.val];
         int minc = min(nc,static_cast<int>(k));
         ll tc = d+ 1LL * k * x.ecost;

         if(dist[x.val][minc] > tc){
            dist[x.val][minc] = tc;
            pq.push({tc,x.val,minc});
         }
      }
   }
   // ll answer = inf;
   // for (int i = 1; i <= 1000; i++) {  
   //    answer = min(answer, dist[e][i]);
   // }

   // return (answer == inf ? -1:answer);
   return bn;
}
void solve(){
   int t;cin>>t;
   while(t--){
      int n,m;cin>>n>>m;
      adj.assign(n+1,vector<node>());

      for(int x = 0 ; x < m ;x++){
         int u,v,c;cin>>u>>v>>c;
         adj[u].push_back({v,c});
         adj[v].push_back({u,c});
      }
      ncost.assign(n+1,0);
      for(int x = 1 ; x <= n ; x++){
         cin >> ncost[x];
      }
      dist.assign(n+1,vector<ll>(1001,inf));
      cout << dijkstra(1,n) << "\n";
   }
}


int main(){
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();
}
