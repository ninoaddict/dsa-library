#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    vector<pair<int, int>> monster;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        int pow;
        cin >> pow;
        monster.push_back({pow, h[i]});
    }

    sort(monster.begin(), monster.end());
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (monster[i].second <= sum)
            continue;
        
        if (i) {
            k -= monster[i].first;
        }

        if (k > 0) {
            sum += k;
            while (monster[i].second > sum) {
                k -= monster[i].first;
                if (k < 0) break;
                sum += k;
            }
        }

        if (monster[i].second > sum) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}