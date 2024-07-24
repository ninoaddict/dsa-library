#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int par = 0;
    int n = s.size();
    int i = 0;

    for (; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            par++;
            s.erase(i, 2);
            i = -1;
            n = s.size();
        }
    }

    if (par % 2 == 1) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}