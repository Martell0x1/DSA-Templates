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

const int N = 1e6;
ll memo[N];

ll fib(int d) {
    if(d <=2) return 1;

    if(memo[d] != -1) return memo[d];

    return memo[d] = fib(d-1)+fib(d-2);
}
void solve() {
    memset(memo , -1, sizeof memo);
    cout << fib(3);
}
int main() {
    FastIO;
#ifdef USACO
    setIO("lineup");
#endif
    solve();

}
