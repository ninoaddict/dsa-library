#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector <int> va, vb;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            va.push_back(i);
            if (i * i != a) {
                va.push_back(a / i);
            }
        }
    }
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            vb.push_back(i);
            if (i * i != b) {
                vb.push_back(b / i);
            }
        }
    }
    for (int f1: va) {
        for (int f2: vb) {
            int div = f1 * f2;
            int x = div;
            int y = a * b / div;
            x = (c / x) * x;
            y = (d / y) * y;

            if (a < x && x <= c && b < y && y <= d) {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}