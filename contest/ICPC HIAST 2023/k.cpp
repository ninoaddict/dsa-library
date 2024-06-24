#include <bits/stdc++.h>
#define int long long int 
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> cnt;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<pair<int, int>> freq(26, {-1, -1});

        for (int j = 0; j < m; j++) {
            int pos = j;             
            while (pos < m && s[j] == s[pos]) {
                pos++;
            }
            freq[s[j] - 'a'] = {j, pos - 1};
            j = pos - 1;
        }

        cnt.push_back(freq);
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int res = 0;

        // iterate over all alphabet
        for (int i = 0; i < 26; i++) {
            if ((cnt[a][i].first == -1 && cnt[a][i].second == -1) || (cnt[b][i].first == -1 && cnt[b][i].second == -1)) continue;
            if (cnt[a][i].first > cnt[b][i].second || cnt[b][i].first > cnt[a][i].second) continue;

            int meow = max(cnt[a][i].first, cnt[b][i].first);
            int woem = min(cnt[a][i].second, cnt[b][i].second);
            res += (woem - meow + 1);
        }

        cout << res << '\n';
    }
}