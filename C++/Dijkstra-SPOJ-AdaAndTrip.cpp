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

void dijkstra(int s){
   priority_queue<node,vector<node>,cmp> pq;
   pq.push({s,0});
   dist[s]=0;

   while(!pq.empty()){
      auto [ch,co] = pq.top();
      pq.pop();

      if(dist[ch] < co) continue;
      for(auto [v,c]: adj[ch]){
         ll tc = c+co;
         if(dist[v] >tc){
            dist[v]=tc;
            pq.push({v,tc});
         }
      }
   }
}
void solve(){
   // #define USACO
   int n,m,q;cin>>n>>m>>q;
   adj.assign(n,vector<node>());
   for(int x = 0 ; x < m ; x++){
      int u,v,c;cin>>u>>v>>c;
      adj[u].push_back({v,c});
      adj[v].push_back({u,c});
   }
   unordered_map<int,pair<ll,ll>> memo;
   unordered_set<int> memoset;
   while(q--){
      int s;cin>>s;
      if(memoset.find(s) != memoset.end()){
         auto [a,b] = memo[s];
         cout << a<< " " << b << "\n";
         continue;
      }

      // dist.clear();
      dist.assign(n,LLONG_MAX);
      dijkstra(s);
      
      ll c = -1;
      int i = -1;
      int cnt = 0;
      for(int x = 0 ; x < n; x++){
         if(dist[x] == LLONG_MAX) continue;
         if(dist[x] > c){
            c=dist[x];
            i=x;
            cnt =1;
         }
         else if(dist[x] == c) cnt++;
      }
      if(c == -1) cout << "0 1\n";
      else cout << dist[i] <<" " <<cnt <<"\n";
      memoset.insert(s);
      memo[s] = {dist[i],cnt};
   }
   

}
