#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5+5;
struct edge{
    ll to,cost;
};
struct node{
    ll index,cost,parent;
};
vector<vector<edge>> adj;
vector<ll> dist,p;
struct cmp{
    bool operator()(const node& a, const node&b){
        return a.cost>b.cost;
    }
};
int dijkstra(int s , int e){
    priority_queue<node , vector<node> , cmp> pq;
    pq.push({s,0,-1});
    dist[s]=0;
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();

        if(v.index == e) return v.cost;


        for(auto ch : adj[v.index]){
            ll newcost = v.cost+ch.cost;
            
            if(newcost < dist[ch.to]){
                dist[ch.to]=newcost;
                pq.push({ch.to,newcost,v.index});
                p[ch.to]=v.index;
            }
        }
    }
    return -1;

}
void print(int n){
    if(n == -1) return;
    ll node = n;
    print(p[node]);
    cout << node << " ";
}
void solve() {
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    dist.assign(n+1,LLONG_MAX);
    p.assign(n+1,-1);
    for(int x = 0 ; x <m ; x++){
        ll u,v,c;cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    ll ans = dijkstra(1,n);
    if(ans != -1){
        print(n);
        return;
    }
    puts("-1");

    
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
