#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    int n;
    cin >> n;

    int numA = 1;
    int numB = 0;

    for (int i = 0; i < n; i++) {
        int newA = numB;
        int newB = numA + numB;

        numA = newA;
        numB = newB;
    }
    cout << numA << " " << numB << '\n';
}