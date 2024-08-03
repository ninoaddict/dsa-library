#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 1001 * 56;
const int MOD = 998244353;

vector<int> fibo(25, 0);
vector<int> val(MAXN, 0);
vector<vector<int>> dp(1001, vector<int> (MAXN, 0));

int conv(int v) {
  int res = 0, curr = v;

  for (int i = 24; i >= 0; i--) {
    if (curr >= fibo[i]) {
      res++;
      curr -= fibo[i];
    }
  }

  return res;
}

void calc() {
  fibo[0] = 1;
  fibo[1] = 1;

  for (int i = 2; i < 25; i++) {
    fibo[i] = fibo[i - 2] + fibo[i - 1];
  }

  for (int i = 0; i < MAXN; i++) {
    val[i] = conv(i);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  calc();

  int n, x, m;
  cin >> n >> x >> m;

  dp[0][0] = 1;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= j * fibo[i]; k++) {
        dp[j + 1][k + fibo[i]] = (dp[j + 1][k + fibo[i]] + dp[j][k]) % MOD;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < MAXN; i++) {
    if (val[i] == m) {
      res = (res + dp[n][i]) % MOD;
    }
  }

  cout << res << '\n';
}