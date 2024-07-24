#include <bits/stdc++.h>
using namespace std;

bool dfs(map <char, char> mp, int v, vector <bool> &vis, vector <bool> &rec) {
    vis[v] = true;
    rec[v] = true;

    if (mp[v + 'a']) {
        if (!vis[mp[v + 'a'] - 'a'] && dfs(mp, mp[v + 'a'] - 'a', vis, rec))
            return true;
        else if (rec[mp[v + 'a'] - 'a']) 
            return true;
    }

    rec[v] = false;
    return false;
}

bool is_valid(map <char, char> mp, char curr, char dest) {
    if (curr == dest) return false;
    mp[curr] = dest;
    vector <bool> vis(26, false);
    vector <bool> rec(26, false);

    for (int i = 0; i < 26; i++) {
        if (!vis[i] && dfs(mp, i, vis, rec)) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    string x;

    cin >> n;
    cin >> x;

    vector <char> used;
    vector <bool> vis(26, false);
    map <char, char> mp;

    for (int i = 25; i >= 0; i--) {
        used.push_back('a' + i);
        mp['a' + i] = 0;
    }

    for (char c: x) {
        if (vis[c - 'a']) continue;
        vis[c - 'a'] = true;

        if (used.size() > 1) {
            stack <int> temp;
            while (!is_valid(mp, c, used.back())) {
                temp.push(used.back());
                used.pop_back();
            }
            mp[c] = used.back();
            used.pop_back();
            while (!temp.empty()) {
                used.push_back(temp.top());
                temp.pop();
            }
        } 
        else {
            mp[c] = used.back();
            used.pop_back();
        }
    }

    for (char c: x) {
        cout << mp[c];
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
