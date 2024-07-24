#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    int n, s;
    cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        res += val;
    }
    if (res == s) {
        cout << n << '\n';
    } else {
        cout << n - 1 << '\n';
    }
}