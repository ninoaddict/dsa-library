#include <bits/stdc++.h>
#define int long long int
using namespace std;

int pw[15];

void prep() {
    pw[0] = 1;
    for (int i = 1; i <= 10; i++) {
        pw[i] = 3ll * pw[i - 1];
    }
}

void solve() {
    int n;
    cin >> n;

    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector <int> dp(pw[10], -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector <int> new_dp(pw[10], -1);
        for (int j = 0; j < pw[10]; j++) {
            if (dp[j] == -1) {
                continue;
            }
            new_dp[j] = max(new_dp[j], dp[j]);
            vector <int> freq(10, 0);
            int val = w[i];
            while (val > 0) {
                freq[val % 10]++;
                val /= 10;
            }
            bool valid = true;
            int curr = 0;
            for (int k = 9; k >= 0; k--) {
                int curr_pow = (j / pw[k]) % 3; // ternary number
                int new_pow = (curr_pow + freq[k]);
                if (new_pow > 2) {
                    valid = false;
                    break;
                }
                curr = curr * 3 + new_pow;
            }
            if (valid) {
                new_dp[curr] = max(new_dp[curr], dp[j] + w[i]);
            }
        }
        dp = new_dp;
    }
    int max_val = 0;
    for (int i = 0; i < pw[10]; i++) {
        if (dp[i] > max_val) {
            max_val = dp[i];
        }
    }
    cout << max_val << '\n';
}

int32_t main() {
    prep();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}