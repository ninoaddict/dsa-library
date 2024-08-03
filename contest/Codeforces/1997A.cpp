#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int idx = -1;

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    if (s[n - 1] == 'a') {
      cout << s + "b" << '\n';
    } else {
      cout  << s + "a" << '\n';
    }
  } else {
    string pad = "a";
    if (s[idx] == 'a') {
      pad = "b";
    }
    cout << s.substr(0, idx + 1) + pad + s.substr(idx + 1) << endl;
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