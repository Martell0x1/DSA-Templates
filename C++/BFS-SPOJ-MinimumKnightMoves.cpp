#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;


vector<vector<int>> dist;
vector<pair<int,int>> moves = {
   {-1,-2},{1,-2},{-2,-1},{2,-1},
   {1,2},{-1,2},{2,1},{-2,1}
};
void bfs(pair<int,int> &sp , pair<int,int> &ep){
   if(sp == ep){
      dist[ep.first][ep.second] = 0;
      return;
   }
   queue<pair<int,int>> q;
   q.push(sp);
   dist[sp.first][sp.second] = 0;

   while(!q.empty()){
      auto [vf,vs] = q.front();
      q.pop();
      for(auto [dx,dy] : moves){
         int nx = vf+dx , ny = vs+dy;
         if(nx >= 0 && nx< 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1){
            q.push({nx,ny});
            dist[nx][ny] = dist[vf][vs]+1;
            if(nx == ep.first && ny == ep.second){
               return;
            }
         }
      }

   }
}
void solve(){
   int t;cin>>t;
   while(t--){
      dist.assign(8,vector<int>(8,-1));
      STR s , e;cin>>s>>e;
      int fs = s[0]-'a' , es = s[1]-'1';
      int se = e[0]-'a' , ee =e[1]-'1';
      pair<int,int> p1 = {fs,es} , p2 ={se,ee};
      bfs(p1,p2);
      cout << dist[p2.first][p2.second] << "\n";
   }
}
int main() {
    FastIO;
    solve();
}
