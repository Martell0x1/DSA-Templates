#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pv(v) for(auto x : v) cout << x << " ";
#define all(v) v.begin(), v.end()
 
typedef string STR;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<long long> vll;
typedef map<ll , ll> mpll;
using namespace std;


void solve() {
    int s,e;cin>>s>>e;
    int dp[e+1] = {};
    dp[s]=1;
    for(int x = s+1 ; x <=e ; x++) {
        for(int c =1;c <= 3;c++) {
            if(x > c) dp[x] +=dp[x-c];
        }
    }
    cout << dp[e];
}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
