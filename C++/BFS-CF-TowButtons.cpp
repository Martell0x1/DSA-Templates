#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N =1e3+5 , M =1e3+5 ,OO=0x3f3f3f3f;
int n,m,u,v;
int bfs(int start , int t){
   if(start >= t) return start - t;
   unordered_map<ll,ll> mp;
   queue<int> q;
   q.push(start);
   mp[start]=0;

   while(!q.empty()){
      int v = q.front();
      q.pop();

      ll s =  mp[v]+1;
      int op1 = v *2 , op2 = v -1;
      if(op1 == t || op2 == t) {
         return s;
      }

      if(op1 < 2*t && mp.find(op1) == mp.end()){
         mp[op1] = s;
         q.push(op1);
      }
      if(op2 > 0 && mp.find(op2) == mp.end()){
         mp[op2] = s;
         q.push(op2);
      }
   }
   return -1;
}
void solve(){
   int n,m;cin>>n>>m;
   cout << bfs(n,m);
}

int main() {
    FastIO;
    solve();
}
