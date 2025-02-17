#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N =1e3+5 , M =1e3+5 ,OO=0x3f3f3f3f;
int n,m,u,v;
vector<pair<pair<int,int>,char>> directions = {
   {{-1,0},'U'}, {{1,0},'D'} , {{0,-1},'L'},{{0,1},'R'}
};
vector<STR> grid;
STR p;
int dis[N][N];
pair<int, int> parent[N][N];
char pStr[N][N];
vector<pair<int,int>> pa;
bool isValid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '#' && dis[r][c] == OO;
}
void bfs(pair<int,int> &src , pair<int,int> &dist){
   queue<pair<int,int>> q;
   q.push(src);
   dis[src.first][src.second]=0;
   parent[src.first][src.second] = {-1,-1};

   while(!q.empty()){
      auto [ua,ub] = q.front();
      q.pop();
      for(auto [dxdy,c]: directions){
         int nr = ua+dxdy.first , nc = ub + dxdy.second;
         if(isValid(nr,nc)){
            dis[nr][nc] = dis[ua][ub]+1;
            parent[nr][nc] = {ua, ub};
            pStr[nr][nc] = c;
            q.push({nr,nc});
            if(nr == dist.first && nc == dist.second) return;
         }
      }

   }
}

STR backtrackPath(pair<int,int>&p , pair<int,int>&p2){
   STR path;
   auto cur = p2;
   while(cur != p){
      auto [pr,pc] = parent[cur.first][cur.second];
      if(pr == -1 && pc == -1) return "NO";
      path.push_back(pStr[cur.first][cur.second]);
      cur = {pr,pc};      
   }
   reverse(path.begin(),path.end());
   return path;
}
    
void solve() {
   memset(dis,OO,sizeof dis);
   memset(pStr,'.',sizeof pStr);
   pair<int,int> A,B;
   cin >>n >> m;
   grid.assign(n,"");
   for(int x = 0 ; x < n ; x++){
      cin >> grid[x];
      for(int c = 0 ; c < grid[x].size() ; c++){
         if(grid[x][c] == 'A') A = {x,c};
         if(grid[x][c] == 'B') B = {x,c};
      }
   }

   bfs(A,B);
   if(dis[B.first][B.second] == OO) cout << "NO";
   else {
      STR p = backtrackPath(A,B);
      cout << "YES\n"<<p.size()<<"\n" << p;
   }

}
int main() {
    FastIO;
    solve();
}
