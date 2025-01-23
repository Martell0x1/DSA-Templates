#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string STR;

int n,m;
char grid[10][10];
vector<STR> vec;
STR path;
void rec(int r, int c){
    if(r == n-1 && c == m-1)
    {
        vec.push_back(path);
        return;
    }
    if(c+1 < m && grid[r][c+1] != '#')
    {
        path.push_back('R');
        rec(r,c+1);
        path.pop_back();
    }
    if(r+1 < n && grid[r+1][c] != '#')
    {
        path.push_back('D');
        rec(r+1,c);
        path.pop_back();
    }
} // time O(!(m + n-2))

int main(){
    cin >> n >>m;
    for(int x = 0 ; x < n ; x++){
        for(int c = 0 ; c < m ; c++) cin >> grid[x][c];
    }
    rec(0,0);
    for(auto x: vec) cout << x << "\n";
}