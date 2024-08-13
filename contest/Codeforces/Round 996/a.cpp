#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s.size() < 3 || s[0] != '1' || s[1] != '0') {
        cout << "NO" << '\n';
        return;
    }

    string ns = s.substr(2, s.size() - 2);
    int nns = stoi(ns);
    string nnns = to_string(nns);

    if (nns >= 2 && ns.size() == nnns.size()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}