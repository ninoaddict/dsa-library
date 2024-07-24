#include <bits/stdc++.h>
#define int long long int
using namespace std;

typedef pair<int, int> pii;

vector <int> djikstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
    vector <int> dist(n + 1, INT64_MAX);
    priority_queue <pii, vector<pii>, greater<pii>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_dist != dist[curr_node]) continue;

        for (auto edge: graph[curr_node]) {
            int to = edge.first;
            int len = edge.second;
            if (curr_dist + len < dist[to]) {
                dist[to] = curr_dist + len;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n + 1);
    vector<vector<pii>> rev(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        rev[v].push_back({u, w});
    }

    int a, b, c;
    cin >> a >> b >> c;

    vector <int> dist_from_a = djikstra(n, graph, a);
    vector <int> dist_from_b = djikstra(n, graph, b);
    vector <int> dist_from_c = djikstra(n, rev, c);

    int min_dist = INT64_MAX;

    for (int i = 0; i < n; i++) {
        if (dist_from_a[i] == INT64_MAX || dist_from_b[i] == INT64_MAX || dist_from_c[i] == INT64_MAX) {
            continue;
        }
        min_dist = min(min_dist, dist_from_a[i] + dist_from_b[i] + dist_from_c[i]);
    }

    if (min_dist == INT64_MAX) {
        cout << -1 << '\n';
    } else {
        cout << min_dist << '\n';
    }
}