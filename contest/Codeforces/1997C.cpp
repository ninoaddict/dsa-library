#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
  int n;
  string s;
  
  cin >> n >> s;
  stack <int> curr;

  int res = 0;

  for (int i = 0; i < n; i++) {
    char p = s[i];
    if (p == '_') {
      if (curr.empty()) {
        p = '(';
      } else {
        p = ')';
      }
    }

    if (p == ')') {
      res += i - curr.top();
      curr.pop();
    } else {
      curr.push(i);
    }
  }

  cout << res << '\n';
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