#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int k = 17;
vector<vector<pair<int, int>>> st;

int max_query(int L, int R) {
    int i = (int)log2(R - L + 1);
    if (st[i][L].first > st[i][R - (1 << i) + 1].first) {
        return st[i][L].second;
    } else {
        return st[i][R - (1 << i) + 1].second;
    }
}

int32_t main() {
    int n;
    cin >> n;

    st.resize(k + 1, vector<pair<int, int>> (n + 1, {-1, -1}));

    int arr[n + 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    arr[n - 1] = n - 1;
    
    // build sparse table
    for (int i = 0; i < n; i++) {
        st[0][i] = {arr[i], i};
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            if (st[i - 1][j].first > st[i - 1][j + (1 << (i - 1))].first) {
                st[i][j] = st[i - 1][j];
            } else {
                st[i][j] = st[i - 1][j + (1 << (i - 1))];
            }
        }
    }

    vector <int> dp(n, 0);
    int res = 0;
    for (int i = n - 2; i >= 0; i--) {
        int mx = max_query(i + 1, arr[i]);
        dp[i] = dp[mx] - (arr[i] - mx) + n - i - 1;
        res += dp[i];
    }

    cout << res << '\n';
}