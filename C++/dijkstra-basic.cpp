#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adj[N];
int dist[N];
struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int> &b){
        return a.second>b.second;
    }
};

int dijkstra(int s , int e){
    priority_queue<pair<int,int> , vector<pair<int,int>> , cmp> pq;
    pq.push({s,0});
    dist[s]=0;
    while(!pq.empty()){
        auto [index,cost] = pq.top();
        pq.pop();

        if(index == e) return cost;

        for(auto [ch,co] : adj[index]){
            int newcost = cost+co;
            
            if(newcost < dist[ch]){
                dist[ch]=newcost;
                pq.push({ch,newcost});
            }
        }
    }
    return -1;

}
void solve() {
    int n,m;cin>>n>>m;
    for(int x = 0 ; x <m ; x++){
        int u,v,c;cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    fill(dist,dist+N,INT_MAX);
    cout << dijkstra(1,7);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
/*
9 9
1 2 4
1 3 5
2 5 2
2 4 2
5 8 6
8 9 5
9 7 8
3 6 8
4 9 12

*/
