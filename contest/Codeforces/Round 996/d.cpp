#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector <int> a(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    string s;
    cin >> s;

    stack <int> sr;
    queue <int> ql;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ql.push(i);
        } else {
            sr.push(i);
        }
    }

    int res = 0;

    while (!sr.empty() && !ql.empty())
    {
        // cari pasangan terluar
        int l = ql.front();
        ql.pop();

        int r = sr.top();
        sr.pop();

        if (l > r) break;

        res += pref[r + 1] - pref[l];
    }

    cout << res << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}