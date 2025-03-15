#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n, m, k;
vector<vector<pair<int, int>>> adj;

vector<ll> dijkstra(int start, int target, int k) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;  
    vector<priority_queue<ll>> dist(n + 1);  

    pq.push({0, start});
    dist[start].push(0);

    vector<ll> results;

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (node == target) {
            results.push_back(cost);
            if (results.size() == k) break;  
        }

        for (auto [next, weight] : adj[node]) {
            ll newCost = cost + weight;

            if (dist[next].size() < k) { 
                dist[next].push(newCost);
                pq.push({newCost, next});
            } else if (newCost < dist[next].top()) {  
                dist[next].pop(); 
                dist[next].push(newCost);
                pq.push({newCost, next});
            }
        }
    }

    return results;
}

void solve() {
    cin >> n >> m >> k;
    adj.assign(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});  
    }

    vector<ll> kShortestPaths = dijkstra(1, n, k);

    for (ll cost : kShortestPaths) {
        cout << cost << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
