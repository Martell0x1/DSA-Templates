#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
   ll val,cost;
};
struct cmp{
   bool operator()(node& a , node&b){
      return a.cost > b.cost;
   }
};
vector<vector<node>> adj;
vector<ll>dist;
unordered_map<int,int> mp;

void dijkstra(int s , int e){
   priority_queue<node,vector<node>,cmp> pq;
   pq.push({s,0});
   dist[s]=0;

   while(!pq.empty()){
      auto [ch,co] = pq.top();
      pq.pop();

      if(dist[ch] < co) continue;
      if(ch == e) return;
      for(auto [v,c]: adj[ch]){
         ll tc = c+co;
         if(dist[v] >tc){
            dist[v]=tc;
            pq.push({v,tc});
            mp[v]=ch;
         }
      }
   }
}
void solve(){
   #define USACO
   int t;cin>>t;
   while(t--){
      int n,m,q;cin>>n>>m>>q;
      int s ; cin>>s;
      pair<int,int>p ;cin>>p.first>>p.second;
      adj.assign(n+1,vector<node>());
      for(int x = 0 ; x < m ; x++){
         int u,v,c;cin>>u>>v>>c;
         adj[u].push_back({v,c});
         adj[v].push_back({u,c});
      }
      vector<int> vec(q);
      for(auto & x : vec) cin >>x;
      sort(vec.begin(),vec.end());
      for(auto x : vec){
         dist.assign(n+1,LLONG_MAX);
         dijkstra(s,x);
         set<pair<int,int>> st;
         for(int c = x ; c!=s;c=mp[c]){
            st.insert({mp[c],c});
         }
         set<int>pq;
         if(st.find({p.first,p.second}) != st.end() ||
         st.find({p.second,p.first}) != st.end()) pq.insert(x);
         for(auto xx : pq) cout << xx <<" ";
         // cout << pq.size();
      }
      cout << "\n";
   }
}

int main(){
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();
}
