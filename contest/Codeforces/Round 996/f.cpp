#include <bits/stdc++.h>
#define int long long int

using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> dp(k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        vector <int> curr = {0};
        while (a > 0 || b > 0) {
            if (a > b) 
                swap(a, b);
            curr.push_back(curr.back() + a);
            b--;
        }
        for (int i = k; i >= 0; i--) {
            for (int j = 0; j < curr.size(); j++) {
                int w = min(i + j, k);
                dp[w] = min(dp[w], dp[i] + curr[j]);
            }
        }
    }

    if (dp[k] < INF) {
        cout << dp[k] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}