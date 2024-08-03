#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector <string> s(2);
  for (int i = 0; i < 2; i++) {
    cin >> s[i];
  }

  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[0][i] == '.' && s[1][i] == '.' && s[0][i - 1] != s[1][i - 1] && s[0][i + 1] != s[1][i + 1] && s[0][i - 1] == s[0][i + 1]) {
      cnt++;
    }
  }

  cout << cnt << '\n';
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