#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector <bool> vis(n, false);

    bool yes = true;

    // check row
    for (int i = 0; i < n && yes; i++) {
        vis.clear();
        vis.resize(n, false);
        for (int j = 0; j < n; j++) {
            if (vis[mat[i][j] - 1]) {
                yes = false;
                break;
            }
            vis[mat[i][j] - 1] = true;
        }
    }

    if (yes) {
        for (int j = 0; j < n && yes; j++) {
            vis.clear();
            vis.resize(n, false);
            for (int i = 0; i < n; i++) {
                if (vis[mat[i][j] - 1]) {
                    yes = false;
                    break;
                }
                vis[mat[i][j] - 1] = true;
            }
        }
    }
    if (yes) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}