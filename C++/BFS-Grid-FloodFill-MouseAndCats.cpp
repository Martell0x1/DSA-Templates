#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;

int n, m;
string grid[N];
vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int disCats[N][M];
int disMouse[N][M];
pair<int,int> parent[N][M];
bool isValid(int r , int c , int who[N][M]){
   if(r < 0 || r >= n || c < 0 || c >= m) return false;
   if(grid[r][c] == '#' || who[r][c] != OO) return false;
   return true;
}
void BFSCats() {
    memset(disCats, OO, sizeof disCats);
    queue<pair<int, int>> q;
    
    for (int x = 0; x < n; x++) {
        for (int c = 0; c < m; c++) {
            if (grid[x][c] == 'C') {
                disCats[x][c] = 0;
                q.push({x, c});
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if (isValid(nr,nc,disCats)) {
                disCats[nr][nc] = disCats[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
}
pair<int,int> exit_pair;
bool BFSMouse(pair<int, int> p) {
    memset(disMouse, OO, sizeof disMouse);
    queue<pair<int, int>> q;
    
    q.push(p);
    disMouse[p.first][p.second] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if (isValid(nr,nc,disMouse) && (disCats[nr][nc] > disMouse[r][c] + 1)) {
                parent[nr][nc] = {r,c};
                if (grid[nr][nc] == 'E'){
                   exit_pair = {nr,nc};
                   return true;
                }
                
                disMouse[nr][nc] = disMouse[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return false;
}

pair<int, int> mp;
void printPath(int r , int c){
   if(r == mp.first && c == mp.second){
      printf("%d %d\n" ,r,c);
      return;
   }
   
   printPath(parent[r][c].first , parent[r][c].second);

   printf("%d %d\n" ,r,c);

}

void solve() {
    cin >> n >> m;
    for (int x = 0; x < n; x++) {
        cin >> grid[x];
        for (int c = 0; c < m; c++) {
            if (grid[x][c] == 'M') mp = {x, c};
        }
    }

    BFSCats();

    cout << "Cats Distance Map:\n";
    for (int x = 0; x < n; x++) {
        for (int c = 0; c < m; c++) {
            if (disCats[x][c] == OO) cout << "- ";
            else cout << disCats[x][c] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMouse can escape? ";
    memset(parent, -1, sizeof parent);
    if(BFSMouse(mp)){
      puts("YES");
      printPath(exit_pair.first,exit_pair.second);
      
    }
    else puts("NO");

    cout << "\nMouse Distance Map:\n";
    for (int x = 0; x < n; x++) {
        for (int c = 0; c < m; c++) {
            if (disMouse[x][c] == OO) cout << "- ";
            else cout << disMouse[x][c] << " ";
        }
        cout << endl;
    }
}
int main() {
   FastIO;
#ifdef USACO
   setIO("lineup");
#endif
   solve();

}


/*
6 5
.E...
C..E.
.C#.#
.#...
C.M..
....E
*/
