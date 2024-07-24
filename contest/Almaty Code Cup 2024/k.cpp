#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int INF = 1e9 + 7;

int32_t main() {
    int n, m, k, b;
    cin >> n >> m >> k >> b;

    k++;

    int a[n + 1][m + 1];
    vector<vector<int>> pref (n + 1, vector <int> (m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pref[i + 1][j] = pref[i][j] + a[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, INF)));

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            for (int ki = 0; ki <= k; ki++) {
                if (ki <= i + 1) 
                    dp[i][j][ki] = pref[i + 1][j] - pref[i + 1 - ki][j];

                if (j < m - 1) {
                    for (int kj = max(0LL, ki - i - 1); kj < ki; kj++) {
                        dp[i][j][ki] = min(dp[i][j][ki], dp[i][j + 1][kj] + pref[i + 1][j] - pref[i + 1 - (ki - kj)][j]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j][k] <= b) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }
}