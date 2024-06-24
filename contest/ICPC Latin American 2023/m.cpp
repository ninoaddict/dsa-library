#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long int
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
vector<pair<int, int>> adj[MAXN];

void djikstra(int n, int s, int skipEdge, vector<int> &d)
{
    vector<bool> vis(n + 1, false);
    priority_queue<pii> pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (vis[v])
            continue;
        vis[v] = true;

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (to == skipEdge)
                continue;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                pq.push({-d[to], to});
            }
        }
    }
}

int32_t main()
{
    fastio int n, m, p, g;

    cin >> n >> m >> p >> g;

    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    vector<int> dist1(n + 1, INF);
    vector<int> dist2(n + 1, INF);

    djikstra(n, p, -1, dist1);
    djikstra(n, p, g, dist2);

    bool ada = false;

    for (int i = 1; i <= n; i++)
    {
        if ((dist1[i] == 2 * dist1[g]) && dist1[i] < dist2[i])
        {
            cout << i << ' ';
            ada = true;
        }
    }

    if (!ada)
    {
        cout << "*";
    }

    cout << '\n';

    return 0;
}