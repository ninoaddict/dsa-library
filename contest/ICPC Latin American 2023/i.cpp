#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main() {
    fastio;
    ll ans = 0, peng, subans = 0;
    ll sum[27];
    ll psum[27];
    memset(sum, 0, sizeof(sum));
    memset(psum, 0, sizeof(psum));
    string s;
    ll t;
    cin >> s;
    cin >> t;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        sum[int(s[i] - 'a')]++;
        psum[1] = sum[0];
        for (int j = 2; j < 27; j++)
        {
            psum[j] = psum[j - 1] + sum[j - 1];
        }
        ans += psum[int(s[i] - 'a')];
    }
    t %= MOD;

    peng = (t) * ((t - 1 + MOD) % MOD) / 2;
    peng %= MOD;

    for (int j = 1; j < 27; j++) {
        subans += psum[j] * sum[j];
        subans %= MOD;
    }
    subans *= peng;
    subans %= MOD;

    ans *= t;
    ans %= MOD;
    ans += subans;
    ans %= MOD;

    cout << ans << endl;
}