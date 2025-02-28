#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;
int n,m,u,v;
vector<int> adj[N];
int deg[N];

bool isEulerian(int n){
    int  o = 0;
    for(int x = 1 ; x <= n ; x++){
        if(deg[x] &1) o++;
    }
    return o == 0 || o == 2; // 0 = cycle , 2 = path
}

int getStart(int n){
    for(int x = 1 ; x <= n ; x++){
        if(deg[x] &1) return x;
    }
    for(int x = 1 ; x <= n ; x++){
        if(!adj[x].empty()) return x;
    }
    return -1;

}
vector<int> path;
void dfs(int s) {
    while (!adj[s].empty()) {
        int v = adj[s].back();
        adj[s].pop_back();
        adj[v].erase(find(adj[v].begin(), adj[v].end(), s)); // Remove reverse edge
        dfs(v);
    }
    path.push_back(s);
}
void solve() {
    cin >> n >> m;
    for(int x = 0 ; x < m ;x++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(isEulerian(n)){
        int s = getStart(n);
        cout << s << "\n";
        dfs(s);
        reverse(path.begin(),path.end());
        for(auto x : path) cout << x << " ";
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
5 7
1  2
2  3
3  1
4  5
5  3
2  4
3  4
*/
