#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;

  vector<int> balances(n, 0);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    
    a--;
    b--;

    balances[a] += c;
    balances[b] -= c;
  }

  vector<pair<int, int>> utang;
  vector<tuple<int, int, int>> res;

  for (int i = 0; i < n; i++) {
    utang.push_back({balances[i], i});
  }

  sort(utang.begin(), utang.end());

  for (int i = 1; i < n; i++) {
    int j = (i + 1) % n;

    if (utang[i].first > 0) {
      res.push_back({utang[j].second + 1, utang[i].second + 1, utang[i].first});
    } else if (utang[i].first < 0) {
      res.push_back({utang[i].second + 1, utang[j].second + 1, -utang[i].first});
    }

    utang[j].first += utang[i].first;
  }

  cout << res.size() << '\n';
  for (auto transaction: res) {
    cout << get<0>(transaction) << " " << get<1>(transaction) << " " << get<2>(transaction) << '\n';
  }
  return 0;
}