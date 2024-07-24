#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (n > 30) {
        cout << -1 << '\n';
    } else {
        int mid = n / 2;
        map<int, int> sub;

        for (int i = 0; i < (1 << mid); i++) {
            int sum = 0;
            for (int j = 0; j < mid; j++) {
                if (i & (1 << j)) {
                    sum += a[j];
                    cout << i << "masuk" << a[j] << '\n';
                }
            }
            sub[sum] = i;
        }
        cout << '\n';
        // second half
        for (int i = 0; i < (1 << (n - mid)); i++) {
            int sum = 0;
            for (int j = 0; j < n - mid; j++) {
                if (i & (1 << j)) {
                    sum += a[mid + j];
                }
            }
            if (sub.find(sum) != sub.end()) {
                int satu = sub[sum];
                int dua = i;

                for (int b = 0; b < mid; b++) {
                    if (satu & (1 << b)) {
                        cout << b + 1 << ' ';
                    }
                }
                cout << '\n';
                for (int b = 0; b < n - mid; b++) {
                    if (dua & (1 << b)) {
                        cout << mid + b + 1 << ' ';
                    }
                }
                cout << '\n';

                return;
            }
        }
        cout << -1 << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
