#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;
    int l = (int) log2(n);
    int res = (1ll << l) - 1ll;
    cout << res << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}