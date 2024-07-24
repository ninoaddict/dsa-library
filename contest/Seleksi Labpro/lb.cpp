#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;

    vector <int> x;
    vector <int> b;
    vector <int> dp(n);
    vector <int> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int xi, yi, bi;
        cin >> xi >> yi >> bi;

        int low = lower_bound(x.begin(), x.end(), yi) - x.begin();

        x.push_back(xi);
        b.push_back(bi);

        dp[i] = (xi - yi + pref[i] - pref[low] + MOD) % MOD;
        pref[i + 1] = (pref[i] + dp[i]) % MOD;
    }

    int res = k;
    for (int i = 0; i < n; i++) {
        if (x[i] > k) 
            break;
        if (b[i])
            res = (res + dp[i]) % MOD;
    }
    cout << res % MOD << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}