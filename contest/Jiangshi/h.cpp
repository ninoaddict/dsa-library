#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    int mat[n + 1][m + 1];
    vector<vector<int>> pref (n + 1, vector <int> (m + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            int curr = pref[n - k + i + 1][m - l + j + 1] - pref[i][m - l + j + 1] - pref[n - k + i + 1][j] + pref[i][j];
            if (curr > 0) {
                res += curr;
            } else {
                res -= curr;
            }
        }
    }
    cout << res << '\n';
    return 0;
}