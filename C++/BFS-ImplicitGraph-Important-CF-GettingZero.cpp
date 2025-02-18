#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N =1e3+5 , M =1e3+5 ,OO=0x3f3f3f3f;
int n,m,u,v;
int mod = 32768;

int bfs(int x) {
    if (x == 0) return 0;
    vector<int> dist(mod,-1);
    queue<int> q;
    q.push(x);
    dist[x]=0;

    while(!q.empty()){
      int v = q.front();
      q.pop();

      int steps = dist[v]+1;
      int op1 = (v + 1) % mod;
      int op2 = (2 * v) % mod;
      if (op1 == 0 || op2 == 0) return steps;

      if (dist[op1] == -1) {
         dist[op1] = steps;
         q.push(op1);
      }

      if (dist[op2] == -1) {
         dist[op2] = steps;
         q.push(op2);
      }
    }
    return -1;
}
void solve() {
   cin>>n;
   while(n--){
      cin>>m;
      cout << bfs(m) << "\n";
   }
}

int main() {
    FastIO;
    solve();
}
