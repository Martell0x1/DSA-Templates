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


struct Cow
{
   int start , end , cool;
};
struct AC
{
   int start , end , cool ,cost;
};

int main()
{
  //define USACO
   int n,m;cin>>n>>m;
   vector<Cow> cows(n);
   vector<AC> aces(m);
   for(int x = 0 ; x < n ; x++) cin >>cows[x].start >> cows[x].end>>cows[x].cool;
   for(int x = 0 ; x < m ; x++) cin >>aces[x].start >> aces[x].end>>aces[x].cool >> aces[x].cost;

   int re =1e9;
   for(int x = 0 ; x< (1ll << m) ;x++)
   {
      int curr = 0;
      vector<int> cooling(101,0);
      for(int b = 0 ; b < m; b++)
      {
         if((1ll << b)&x)
         {
            curr += aces[b].cost;
            for(int c =aces[b].start;c<= aces[b].end ; c++) cooling[c]+=aces[b].cool;
         }
      }
      bool valid = true;
      for(int x = 0; x < n; x++)
      {
         for(int j = cows[x].start; j<=cows[x].end;j++)
         {
            if(cows[x].cool > cooling[j])
            {
               valid = false;break;
            }
         }
      }
      if(valid) re = min(re,curr);
   }
   cout <<re;
   return 0;

}
