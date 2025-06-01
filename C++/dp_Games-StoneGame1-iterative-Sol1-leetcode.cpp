class Solution {
public:
    bool stoneGame(const vector<int>& piles) {
        int dp[501][501][2] = {};
        int n = piles.size();
        for(int x = 0 ; x < n ; x++){
            dp[x][x][0] = piles[x];
            dp[x][x][1] = 0;
        }
        for(int len = 2 ; len <= n ; len++){
            for(int i=0;i + len-1 <n ;i++){
                int j = i + len - 1;

                dp[i][j][0] = max(
                    piles[i] + dp[i+1][j][1],
                    piles[j] + dp[i][j+1][1]
                );

                dp[i][j][1] = max(
                    piles[i] + dp[i+1][j][0],
                    piles[j] + dp[i][j+1][0]
                );
            }
        }
        int total = accumulate(piles.begin(), piles.end(), 0);
        return dp[0][n-1][0] > total - dp[0][n-1][0];
    }
};
