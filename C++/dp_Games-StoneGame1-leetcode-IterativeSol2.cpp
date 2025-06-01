class Solution {
public:
    bool stoneGame(const vector<int>& piles) {
        int dp[501][501] = {};
        int n = piles.size();
        for(int x = 0 ; x < n ; x++){
            dp[x][x]= piles[x];
        }
        for(int len = 2 ; len <= n ; len++){
            for(int i=0;i + len-1 <n ;i++){
                int j = i + len - 1;

                dp[i][j] = max(
                    piles[i] - dp[i+1][j],
                    piles[j] - dp[i][j+1]
                );
            }
        }
        return dp[0][n-1]>0;
    }
};
