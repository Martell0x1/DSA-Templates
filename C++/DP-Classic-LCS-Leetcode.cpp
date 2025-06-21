class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        std::function<int(int,int)> solve = [&](int i , int j) -> int{
            if(i == n || j == m) return 0;
            int& ret = dp[i][j];
            if(~ret) return ret;

            if(text1[i] == text2[j]) return ret = 1+solve(i+1,j+1);
            return ret = max(solve(i+1,j),solve(i,j+1));
        };

        return solve(0,0);
    }
};
