#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;


const int N = 1e3 , M=5e4;
int n,m,d,u;
int IN[N];
vector<int> adj[N];

int BFS(){
   int cnt = 0;
   bool ok = false;
   queue<int> q;
   for(int x = 1 ; x <= n ; x++){
      if(IN[x] == 0){
         q.push(x);
      }
   }

   while(!q.empty()){
      if(q.size() >1) ok =true;
      int u = q.front();
      q.pop();
      cnt ++;
      for(auto v : adj[u]){
         IN[v]--;
         if(IN[v] == 0){
            q.push(v);
         }
      }
   }
   if(cnt != n) return 0;
   if(ok) return 2;
   return 1;

}
void reset(){
   memset(IN,0,sizeof IN);
   for(int x =  1 ; x <=n ; x++){
      adj[x].clear();  
   }
}
void solve(){
   while(scanf("%d %d",&n,&m) , n || m){
      reset();
      for(int x =0; x < m ; x++){
         cin >> d >> u;
         adj[d].push_back(u);
         IN[u]++;
      }
      cout << BFS() << "\n";

   }
}
int main() {
    FastIO;
    solve();
}
