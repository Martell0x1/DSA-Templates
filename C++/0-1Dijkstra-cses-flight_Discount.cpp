#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
 
vector<vector<pair<int, ll>>> adj;
vector<vector<ll>> dist;
 
ll dijkstra(int s, int e) {
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
    pq.push({0, s, 0}); // {cost, node, used_coupon}
    dist[s][0] = 0;
 
    while (!pq.empty()) {
        auto [c, v, st] = pq.top();
        pq.pop();
 
        if (c > dist[v][st]) continue;
 
        for (auto [ch, co] : adj[v]) {
            ll tc1 = c + co;
            if (dist[ch][0] > tc1) {
                dist[ch][0] = tc1;
                pq.push({tc1, ch, 0});
            }
 
            if (st == 0) {
                ll tc2 = c + co / 2;
                if (dist[ch][1] > tc2) {
                    dist[ch][1] = tc2;
                    pq.push({tc2, ch, 1});
                }
            }
        }
    }
 
    return min(dist[e][0], dist[e][1]);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<pair<int, ll>>());
    dist.assign(n + 1, vector<ll>(2, inf));
 
    for (int x = 0; x < m; x++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
 
    cout << dijkstra(1, n) << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
