#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


typedef long long ll;
ll add(ll a, ll b, ll mod){
    return (a%mod + b % mod) %mod;
}
ll sub(ll a , ll b , ll mod){
    a%=mod;
    b%=mod;
    ll ret = a-b;
    ret %=mod;
    ret += mod;
    ret %=mod;
    return ret;
}
ll mul(ll a , ll b ,ll mod){
    return ((a % mod) *(b % mod)) %mod;
}

ll fastPower(ll a, ll b, ll mod){
    if(!b) return 1;
    a%=mod;
    ll rn = fastPower(a,b>>1,mod) % mod;
    return (b&1) ? (((rn%mod)*rn%mod)%mod *a)%mod: (rn%mod*rn%mod)%mod;
}

vector<int> divs;
void divisors(ll n){
    for(int x = 1 ; x*x <= n; x++){
        if(n % x == 0) {
            divs.push_back(x);
            if(x*x != n) divs.push_back(n/x);
        }
    }
}

ll gcd(ll a , ll b){
    if(b > a){
        b^=a;
        a^=b;
        b^=a;
    }
    if (b == 0) return a;
    return gcd(a%b,b);
}
ll lcm(ll a , ll b){
    return a*b / gcd(a,b);
}

int main(){
    cout << gcd(0,24);
    return 0;
}