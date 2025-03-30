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

const int N =2e3+1 , M= 2e3+1 , inf = 0x3f3f3f3f;
int dp[N][M];
int w[N],p[N];

int rec(int n, int rem) {
    if(n == 0 || rem == 0) return 0;

    int &  ret = dp[n][rem];
    if(ret != -1) return ret;

    int op1 = (w[n-1] <= rem ? rec(n-1,rem-w[n-1]) + p[n-1]:-inf);
    int op2 = rec(n-1,rem);
    return ret = max(op1,op2);
}

int iterative(int n, int rem) {
    for(int x = 0 ; x <= n ; x++) dp[x][0] = 0;
    for(int x = 0 ; x <= rem ; x++) dp[0][x] = 0;

    for(int x = 1 ; x <= n ; x++) {
        for(int c = 1 ; c <= rem ; c++) {
            int op1 = (w[x] <= c ? dp[x-1][c-w[x]] + p[x] : -inf);
            int op2 = dp[x-1][c];
            dp[x][c] = max(op1, op2);
        }
    }
    return dp[n][rem];
}

void solve() {
    int s,k;cin>>s>>k;
    memset(dp,-1,sizeof dp);
    for(int x = 1  ; x<=s ; x++) {
        cin >> w[x] >> p[x];
    }
    cout << iterative(k,s);

}

int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
