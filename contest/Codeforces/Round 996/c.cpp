#include <bits/stdc++.h>
#define int long long int
using namespace std;

bool cek(vector <int> a, string s) {
    map<char, int> mp;
    map<int, char> mp2;

    for (int i = 0; i < a.size(); i++) {
        if (mp.find(s[i]) == mp.end() && mp2.find(a[i]) == mp2.end()) {
            mp[s[i]] = a[i];
            mp2[a[i]] = s[i];
        } else if (mp[s[i]] == a[i] && mp2[a[i]] == s[i]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (s.size() == n && cek(a, s)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}