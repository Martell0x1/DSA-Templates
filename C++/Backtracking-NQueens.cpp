#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string STR;

int N_;
char grid2[10][10];
bool isValid(int r , int c)
{
    for(int r1 = r-1 , c2 = c-1 ; r1 >= 0 && c2 >=0 ; r1--,c2--)
        if(grid2[r1][c2] == '#') return false;
    for(int r1 = r-1 , c2 = c+1; r1 >= 0 && c2 <N_ ; r1--,c2++)
        if(grid2[r1][c2] == '#') return false;
    for(int r1 = r-1 ; r1 >= 0 ; r1--)
        if(grid2[r1][c] == '#') return false;
    return true;

} // can be optimized using freq array

int ans = 0;
void rec(int r)
{
    if(r == N_)
    {
        ans ++;
        for(int x = 0 ; x <N_ ; x++){
            for(int y = 0 ; y < N_ ; y++){
                cout << grid2[x][y];
                if(y+1==N_) cout << "\n";
            }
            cout << "----\n";
        }
        cout << "*************************\n";
        return;
    }
    for(int x = 0 ; x < N_ ; x++)
    {
        if(isValid(r,x))
        {
        grid2[r][x] = '#';
        rec(r+1);
        grid2[r][x] = '.';
        }
    }
} // O(n^n)
int main(){
    cin >> N_;
    for(int x = 0 ; x < N_ ; x++){
        for(int c = 0 ; c < N_ ; c++) grid2[x][c]='.';
    }
    cout << "Grid:\n";
    rec(0);
    cout << "\nSolutions: "<<ans;

}