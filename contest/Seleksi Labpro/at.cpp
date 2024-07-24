#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector <int> res(n, -1);
    stack <int> st;

    for (int i = 0; i < n; i++) {
        int elmt;
        cin >> elmt;

        while (!st.empty() && st.top() >= elmt) {
            st.pop();
        }

        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(elmt);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}