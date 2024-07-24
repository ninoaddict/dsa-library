#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    int x, y;
    cin >> x >> y;

    double res = (1 + sqrt(1 + 8 * y)) / 2;
    int hasil = floor(res);
    hasil = min(hasil, x);

    cout << hasil << '\n';
}