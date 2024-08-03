#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 2e5 + 7;

int t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int32_t main() {
  int n, q;

  cin >> n >> q;;

  int arr[n + 1];
  int dp[n + 1];

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    int l = 1, r = n, mid, res = 0;
    while (l <= r) {
      mid = (l + r) / 2;
      if (i - 1 - sum(1, 1, n, mid, n) >= mid * arr[i]) {
        res = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    dp[i] = res;
    if (res > 0) {
      update(1, 1, n, dp[i], 1);
    }
  }

  while (q--) {
    int x, y;
    cin >> x >> y;

    cout << (y > dp[x] ? "YES" : "NO") << '\n';
  }
}