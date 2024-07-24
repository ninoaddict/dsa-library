#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6;
vector <int> lp(MAXN + 1);
vector <int> pr;

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void linear_sieve() {
    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        } 
        for (int j = 0; i * pr[j] <= MAXN; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> primes;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        // factorize
        while (v > 1) {
            int prime = lp[v];
            int cnt = 0;
            while (v % prime == 0) {
                v /= prime;
                cnt++;
            }
            primes[prime].push_back(cnt);
        }
    }

    vector <int> res(n, 1);

    for (auto prm: primes) {
        int prmnum = prm.first;
        vector <int> prmpow = prm.second;
        sort(prmpow.rbegin(), prmpow.rend());
        // cout << prmnum << ": ";
        for (int i = 0; i < prmpow.size(); i++) {
            // cout << prmpow[i] << ' ';
            res[i] = (res[i] * binpow(prmnum, prmpow[i], MOD)) % MOD;
        }
        // cout << "\n";
    }

    int meow = 0;
    for (int i = 0; i < n; i++) {
        meow = (meow + res[i]) % MOD;
    }
    cout << meow % MOD << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    linear_sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}