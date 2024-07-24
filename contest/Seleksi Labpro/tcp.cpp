#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    map <int, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        if (mp[k - el] > 0) {
            res++;
            mp[k - el]--;
        } else {
            mp[el]++;
        }
    }
    cout << res << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}