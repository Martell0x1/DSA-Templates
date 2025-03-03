class Solution {
private:
    struct node{
        pair<int,int>  e;
        double prop;
    };
    struct cmp{
        bool operator()(node &a , node&b){
            return a.prop < b.prop;
        }
    };
    vector<vector<pair<int,double>>> getAdj(vector<vector<int>>&edges,vector<double>&prop,int&n){
        vector<vector<pair<int,double>>> re(n);
        for(int x = 0 ; x < edges.size() ; x++){
            int u = edges[x][0],v=edges[x][1];
            re[u].push_back({v,prop[x]});
            re[v].push_back({u,prop[x]});
        }
        return re;
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> probTotal(n,0.0);
        vector<vector<pair<int,double>>> adj = getAdj(edges,succProb,n);
        auto dijkstra = [&](int start , int end)->double
        {
            priority_queue<node,vector<node>,cmp>pq;
            pq.push({{start_node,-1},1.0});
            probTotal[start_node]=1.0;

            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                if(top.e.first == end_node) return top.prop;

                for(auto [node,prop] : adj[top.e.first]){
                    double t = prop * top.prop;
                    if (probTotal[node] < t) {
                        probTotal[node] = t;
                        pq.push({{node, top.e.first}, t});
                    }
                }
            }
            return 0;
        };
        double re= dijkstra(start_node,end_node);
        return re;
    }
};
