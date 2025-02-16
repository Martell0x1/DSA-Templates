#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N =1e5+5 , M =2e5+5 ,OO=0x3f3f3f3f;
int n,m,u,v;
vector<pair<int,int>> moves = {
   {1,0},{-1,0},{0,1},{0,-1},
   {-1,1},{1,-1},{1,1},{-1,-1}
};
map <int,set<int>> allowed;
map<pair<int,int>,int> dis;
bool isValid(int r, int c) {
    return allowed[r].count(c) && dis.find({r, c}) == dis.end();
}

void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : moves) {
            int nr = r + dr, nc = c + dc;
            if (isValid(nr, nc)) {
                dis[{nr, nc}] = dis[{r, c}] + 1;
                if (nr == end.first && nc == end.second) return;
                q.push({nr, nc});
            }
        }
    }
}

    
void solve() {
   int x0, y0, x1, y1;
   cin >> x0 >> y0 >> x1 >> y1;

   int n;
   cin >> n;

   for (int i = 0; i < n; i++) {
      int r, a, b;
      cin >> r >> a >> b;
      for (int c = a; c <= b; c++) {
         allowed[r].insert(c);
      }
   }

   bfs({x0, y0}, {x1, y1});

   if (dis.find({x1, y1}) != dis.end()) {
      cout << dis[{x1, y1}] << "\n";
   } else {
      cout << "-1\n";
   }

}
int main() {
    FastIO;
    solve();
}
