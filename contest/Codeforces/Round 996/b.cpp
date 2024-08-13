#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector <bool> b(n, false);
    bool istrue = true;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;

        if (i && istrue) {
            bool bisa = false;

            if (a > 0 && b[a - 1]) {
                bisa = true;
            }

            if (a < n - 1 && b[a + 1]) {
                bisa = true;
            }
            
            if (!bisa) {
                istrue = false;
            }
        }

        b[a] = true;
    }

    if (istrue) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}