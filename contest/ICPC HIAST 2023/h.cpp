#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;

    set <int> pos;
    multiset <int> val;
    vector <int> arr(n);
    vector <int> res;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        pos.insert(i);
        val.insert(v);
        arr[i] = v;
    }

    res.push_back(*val.rbegin());
    
    int q;
    cin >> q;
    while (q--) {
        int curr;
        cin >> curr;
        curr--;
        int nxt = *(pos.upper_bound(curr));
        arr[nxt] += arr[curr];
        pos.erase(pos.find(curr));
        val.insert(arr[nxt]);
        res.push_back(*val.rbegin());
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}