#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f;
int n,m,u,v;
vector<int> adj[N];
int IN[N] , OUT[N];

int getStart(int n){
    int s = -1;
    for(int x = 1 ;x <= n ; x++){
        if(OUT[x]-IN[x] == 1) return x; // find first node
        if(OUT[x] > 1 && s == -1) s = x; //any node with outing edge
    }
    return s;
}
bool isEulerian(int n){
    int start = 0 , end = 0;
    for(int x = 1 ; x <= n ; x++){
        int diff = OUT[x] - IN[x];
        if(diff >1 || diff <-1) return false;
        if(diff == 1) start++;
        if(diff == -1)  end++;
    }
    return (start == 1 && end == 1) || (start == 0 && end == 0); // 1=path , 2 = cycle
}
vector<int> path;
void dfs(int s){
    while(!adj[s].empty()){
        int v = adj[s].back();
        adj[s].pop_back();
        dfs(v);
    }
    path.push_back(s);
}

void solve() {
    cin >> n >> m;
    for(int x = 0 ; x < m ;x++){
        cin >> u >> v;
        adj[u].push_back(v);
        IN[v]++;
        OUT[u]++;
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
