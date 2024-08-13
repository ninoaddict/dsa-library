#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n, m, k, w;    
    cin >> n >> m >> k >> w;

    vector <int> gorillas(w);
    for (int i = 0; i < w; i++) {
        cin >> gorillas[i];
    }
    sort(gorillas.rbegin(), gorillas.rend());

    vector <int> mult(n * m, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m / 2) {
                mult[i * m + j] *= min(j + 1, min(k, m - k + 1));
            } else {
                mult[i * m + j] *= min(m - j, min(k, m - k + 1));
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                mult[i * m + j] *= min(i + 1, min(k, n - k + 1));
            } else {
                mult[i * m + j] *= min(n - i, min(k, n - k + 1));
            }
        }
    }

    sort(mult.rbegin(), mult.rend());
    int res = 0;

    for (int i = 0; i < w; i++) {
        res += gorillas[i] * mult[i];
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