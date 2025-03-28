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

const int N = 1e3,M=1e3;
int n;
int w[N],p[N], MAXW[N][M];

ll knap(int n,int wt) { //time o(N*M)
    if(n == 0 || wt == 0) return 0;

    if(MAXW[n][wt] != -1)return MAXW[n][wt];
    ll take = -1;
    if(w[n-1] <= wt) {
        take = p[n-1] + knap(n-1,wt - w[n-1]);
    }
    ll leave = knap(n-1,wt);
    return MAXW[n][wt]=max(take,leave);
}

void solve() {
    int n;cin>>n;
    int fib[n+1] = {};
    fib[1]=0,fib[2] = 1;
    for(int x = 3 ; x <= n ; x++) {
        fib[x] = fib[x-1] + fib[x-2];
    }
    cout << fib[n];
}
/*
5 12
3 10
4 20
5 50
7 5
8 80
 */
int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}

