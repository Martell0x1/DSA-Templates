#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
   int t;cin>>t;
   while(t--){
      int n,m;cin>>n>>m;
      STR initm;cin>>initm;
      int initma = binc(initm);

      vector<int> cure(m+1) , add(m+1),cost(m+1);
      for(int x = 0 ; x <m ; x++){
         int d;cin>>d;
         STR re;cin>>re;
         STR ad;cin>>ad;
         cure[x]=(binc(re));
         add[x]=(binc(ad));
         cost[x]=(d);
      }
      if(initma == 0) {
         cout << 0 << "\n";
         continue;
      }

      vector<int>dist(1<<n,INT_MAX);
      priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
      pq.push({0,initma});
      dist[initma] = 0;
      while(!pq.empty()){
         auto [co,ch] = pq.top();
         pq.pop();

         if(dist[ch] < co) continue;
         if(ch == 0) break;

         for(int x =0 ; x <m ; x++){
            int tc = cost[x] + co;
            int newmks = (ch & ~cure[x]) | add[x];
            if(dist[newmks] > tc){
               pq.push({tc,newmks});
               dist[newmks] = tc;
            }
         }
      }
      cout << (dist[0] == INT_MAX ? -1:dist[0]) << "\n";
      
   }
}

int main(){
   ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   solve();
}
