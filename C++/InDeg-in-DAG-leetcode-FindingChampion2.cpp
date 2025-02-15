class Solution {
public:
    bool BFS(int src , vector<vector<int>>&adj , vector<int>&vis , int n){
        vis[src]=1;
        queue<int> q;
        q.push(src);
        int count = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(vis[v] == 0){
                    vis[v]=1;
                    q.push(v);
                    count++;
                }
            }
        }
        return count == n;
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_deg(n,0);
        vector<vector<int>> adj(n);
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            in_deg[x[1]]++;
        }

        int start = -1;
        for(int x  = 0 ; x < n ; x++){
            if(in_deg[x] == 0){
                if(start != -1) return -1;
                start =x;
            }
        }
        vector<int> vis(n);
        return (BFS(start,adj,vis,n) ? start:-1);

    }
};
