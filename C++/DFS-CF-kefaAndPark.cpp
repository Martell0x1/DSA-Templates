/* Use the slash-star style comments or the system won't see your
identification information */
/*
ID: marawan1
TASK: test
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */

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
__int128 read(){
   __int128 x = 0 , f = 1;
   char ch = getchar();
   while(ch < '0' || ch > '9'){
      if(ch == '-') f=-1;
      ch = getchar();
   }
   while(ch >= '0' && ch <= '9'){
      x = x* 10 + ch - '0';
      ch = getchar();
   }
   return x * f;
}
void print(__int128 x){
   if(x < 0){
      putchar('-');
      x*=-1;
   }
   if(x > 9)print(x/10);
   putchar(x %10 + '0');
}
vector<STR> substr(STR str){
   vector<STR> vec;
   for(int x = 0 ; x < str.size() ; x++){
      STR sub;
      for(int c = x ; c < str.size() ; c++){
         sub +=str[c];
         vec.push_back(sub);
      }
   }
   return vec;
}
ll fastpow(ll x , ll b , ll mod)
{
   x%=mod;
   if(b == 0) return 1;
    ll m = fastpow(x,b/2,mod)%mod;
    if(b%2) return (((m * m)%mod) *x)%mod;
   return (m*m)%mod;
}
template<typename T>
T fastSqrt(T s){ // log(log(n))
   if(s < 0) return -1;
   if(s == 0 || s == 1) return s;
    T x = s;
   T y = (x+s /x)/2;
   while(y < x){
      x= y;
      y = (x+s/x)/2;
   }
   return x;
}
vector<ll> PrimeFactors(ll n) {
   vector<ll> factors;
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
         factors.push_back(i);
         while (n % i == 0) n /= i;
      }
   }
   if (n > 1) factors.push_back(n);
   return factors;
}
  ll lcm(ll a, ll b) {
   return (a / __gcd(a, b)) * b;
}
 bool endsWith(STR s1,STR s2)
{
   return s1.compare(s1.size()-s2.size(),s2.size(),s2) == 0;
}

bool KnowBit(ll n , int i)
{
   return (n >>i)&1;
}

ll SetBit(ll n , int i)
{
   return n|=(1<<i);
}

ll ResetBit(ll n ,int i)
{
   return n &(~(1 << i));
}

ll ResetBit2(ll n , int i)
{
   return n&(-1^(1<<i));
}

ll FlipBit(ll n , int i)
{
   return n ^(1<<i);
}

bool isPowOfTow(ll n)
{
   return (n==0?0:!(n&(n-1)));
}

const long double PI = acos(-1.0);

void setIO(STR name)
{
   // ofstream f(name+".in");
   ifstream infile(name+".in");
   if(!infile.good()) ofstream outfile(name+".in");
   freopen((name+".in").c_str(),"r",stdin);
   freopen((name+".out").c_str(),"w",stdout);
}

const int N = 100;
vector<int> Isprime(N+7,1);
vector<int> primes;

void seive(ll n)
{
   Isprime[0]=Isprime[1]=0;
   for(ll x = 2; x* x <=N ; x++)
   {
      if(Isprime[x])
      {
         for(ll o = x*x ;o<=N;o+=x) Isprime[o]=0;
      }
   }
   // return primes[n];
}
void LSeive()
{
   Isprime[0]=Isprime[1]=0;
   for(int x = 2 ; x < N; x++)
   {
      if(Isprime[x]) primes.push_back(x);
      for(auto it : primes)
      {
         if(x * it > N) break;
         Isprime[x*it] = 0;
         if(x % it == 0) break;
      }
   }
}

int Phi(int n)
{
   float re = n;
   for(ll x = 2 ; x*x <= n ; x++)
   {
      if(n%x == 0)
      {
         while(n%x == 0) n/=x;
         re *= (1.0-1.0/(float)x);
      }
   }
   if(n>1) re*= (1.0-1.0/(float)n);
   return (int)re;
}

int Phi2(int n)
{
   int re = n;
   for(ll x = 2 ; x * x <= n ; x++)
   {
      if(n%x == 0)
      {
         while(n%x == 0) n/=x;
         re -= x;
      }
   }
   if(n>1) re-=n;
   return re+1;
}
priority_queue<int> facts;
void s(int k)
{
   for(int x = 1 ; x* x <= k ; x++)
   {
      if(k%x == 0) {
         facts.push(x);
         if(x*x != k) facts.push(k/x);
      }
   }
}
bool isSubstring(const string &x, const string &s) {
   return x.find(s) != string::npos;
}

const int N_=10e5+6,M=2*10e5+6;
const int NOT_VISITED = 0 , IN_PROGRESS = 1 , VISITED = 2;
int m,n,u,v;
vector<int> adj[N_];
bool vis[N_];
unordered_map<int,int> mp;
int c1=0 , c2=1;

void dfs(int u)
{
   vis[u]=true;
   if(mp[u] > m) return;
   if(adj[u].size() == 1 && c2>1) c1++; // are you leaf and not root ?
   c2++;
   for(auto v : adj[u])
   {
      if(!vis[v]) {
         if(mp[v] > 0) mp[v]+=mp[u];
         dfs(v);
      }
   }
}

void solve()
{
   // #define USACO;
   cin>>n>>m;
   for(int x = 1 ; x <=n;x++){
      int k;cin>>k;
      mp[x]=k;
   }
   for(int x = 0 ;x <n-1;x++){
      cin>> u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   dfs(1);
   cout << c1;



}

int main() {
   FastIO;
#ifdef USACO
   setIO("lineup");
#endif
   solve();

}



