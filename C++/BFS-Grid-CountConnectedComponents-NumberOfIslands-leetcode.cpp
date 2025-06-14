class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int N = 300 , M = 300 , OO = 0x3f3f3f3f;
        int n = grid.size() , m = grid[0].size();
        vector<pair<int,int>> dxdy = {{0,1},{1,0},{0,-1},{-1,0}};
        auto isValid = [&](int x , int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1';
        };
        auto bfs = [&](int x , int y) -> void {
            queue<pair<int,int>> q;
            grid[x][y]='0';

            q.push({x,y});
            while(!q.empty()){
                auto [x ,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dxdy){
                    int nx = x+dx , ny = y+dy;
                    if(isValid(nx,ny)){
                        grid[nx][ny]='0';
                        q.push({nx,ny});
                    }
                }
            }
        };
        int re = 0;
        for(int x = 0 ; x < n ; x++){
            for(int y = 0 ; y<m ; y++){
                if(grid[x][y] == '1'){
                    bfs(x,y);
                    re++;
                }
            }
        }
        return re;
    }
};