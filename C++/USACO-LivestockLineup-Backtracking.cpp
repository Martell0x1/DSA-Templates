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

vector<STR> vec = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<vector<STR>> mat;
vector<pair<STR,STR>> rules;
void red(vector<STR> &curr , vector<STR>&rem ,vector<bool>&used )
{

   if(curr.size()==rem.size())
   {
      mat.push_back(curr);
      return;
   }
   for(int x = 0; x <8 ; x++)
   {
      if(used[x]) continue;

      if(x >0 && rem[x] == rem[x-1] && !used[x-1]) continue;

      used[x]=true;
      curr.push_back(vec[x]);
      red(curr,rem,used);
      used[x] = false;
      curr.pop_back();
   }
}
bool isValid(vector<STR>& perm)
{
   for(auto x : rules)
   {
      STR cow1 = x.first ,cow2=x.second;
      auto itr1 = find(perm.begin(),perm.end(),cow1);
      auto itr2 = find(perm.begin(),perm.end(),cow2);
      if(abs(distance(itr1,itr2)) != 1) return false;
   }
   return true;
}
int main()
{
  //#define USACO;
   int n;cin>>n;
   rules.resize(n);

   for(int x = 0  ; x < n ; x++)
   {
      STR c1,c2,tmp;cin >>c1>>tmp>>tmp>>tmp>>tmp>>c2;
      rules[x] = {c1,c2};
   }
   sort(vec.begin(),vec.end());
   vector<bool>used (vec.size(),false);
   vector<STR> c;
   red(c,vec,used);

   for(auto x : mat)
   {
      if(isValid(x))
      {
         for(auto c : x)cout<<c<<"\n";
         break;
      }
   }
}
