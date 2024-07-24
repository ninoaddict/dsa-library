#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector <int> right(n, 1);
    vector <int> left(n, 1);

    int res = 1;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] > arr[i]) {
            right[i] = right[i + 1] + 1;
        }
        res = max(res, right[i]);
    }

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            left[i] = left[i - 1] + 1;
        }
        res = max(res, left[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        if (arr[i] < arr[i + 2]) {
            res = max(res, left[i] + right[i + 2]);
        }
    }

    cout << res << '\n';
}