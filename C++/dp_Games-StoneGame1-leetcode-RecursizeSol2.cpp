class Solution {
public:
    int dp[501][501];
    int solve(const vector<int>& piles , int i , int j){
        if(i == j) return piles[i];
        
        int& ret = dp[i][j];
        if(ret != -1) return ret;

        int left = piles[i] - solve(piles,i+1,j);
        int right = piles[j] - solve(piles,i,j-1);
        
        return ret = max(left,right);

    }
    bool stoneGame(const vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        return solve(piles,0,piles.size()-1) > 0;
    }
};
