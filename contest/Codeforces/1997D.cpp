#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e17;
const int maxn = 2e5 + 7;

vector <int> adj[maxn];
int dp[maxn];
int arr[maxn];

void dfs(int v) {
  dp[v] = INF;

  for (auto u: adj[v]) {
    dfs(u);
    dp[v] = min(dp[v], dp[u]);
  }

  if (!adj[v].size()) {
    dp[v] = arr[v];
  }

  if (v && arr[v] < dp[v]) {
    dp[v] = (arr[v] + dp[v]) / 2LL;
  }
}

void solve() {
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    a--;

    adj[a].push_back(i);
  }

  dfs(0);

  cout << dp[0] + arr[0] << '\n';
  for (int i = 0; i < n; i++) {
    adj[i].clear();
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}