#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
// t1
#define gc getchar_unlocked
#define pii pair<long long, long long>
using ll = long long;
using cd = complex<double>;

const ll maxN = 1e6 + 10, maxM = 2e6 + 10, MAX = 2e6 + 10;
//const ll maxScore = 4294967295;
const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = acos(-1.0);
const double e = exp(1.0);
const ll naught = -100001;
const ll maxT = ceil(sqrt(maxN)) + 1;
const ll root_rec = 15311432;
const ll root_1 = 469870224;
const ll root_pw = (1 << 23);
const int K = 20;
const int g = 3;
const int LOGN = 20;
const int num1 = 16;
const int INF = 1e9;
//const ll is_query = -(1LL<<62)

ll pref[maxN];

template <typename T> void fastInt(T& angka) {
    T kali = 1; angka = 0; char input = gc();
    while (!isdigit(input)) { if (input == '-') kali = -1; input = gc(); }
    while (isdigit(input)) angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
    angka *= kali;
}

void fastStr(string& str) {
    str = "";
    char c = '0';
    while ((c = gc()) && (c != -1 && c != '\n' && c != '\t' && c != '\r' && c != ' ')) {
        str += c;
    }
}

ll powMod(ll x, ll y, ll p){
    ll res = 1;
    x %= p;
    if(!x) return 0;
    while (y > 0){
        if (y & 1) res = ((res % p) * (x % p)) % p;
        y = y >> 1;
        x = ((x % p) * (x % p)) % p;
    }
    return res;
}

ll inverseMod(ll x, ll p){
    return powMod(x, p - 2, p);
}

void solve(){
    ll n; fastInt(n);
    vector<ll> arr(n);
    for(auto &x: arr) fastInt(x);
    for(int i = 1; i < n; i++){
        ll uwu = -1;
        if(arr[i] > arr[i - 1]) uwu = 1;
        pref[i] = pref[i - 1] + uwu;
    }
    map<ll, ll> umap;
    ll ans = 0;
    umap[0] = 1;
    for(int i = 1; i < n; i++){
        ll k = pref[i];
        ans += umap[k];
        umap[k]++;
    }
    cout << ans + n << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(10);
    //auto beg = high_resolution_clock::now();
    //cout << req(1e7 + 8) << '\n';
    int t; t = 1;
    while(t--) solve();
    //auto en = high_resolution_clock::now();
    //auto dur = duration_cast<microseconds>(en - beg);
    //cout << dur.count() << endl;
    return 0;
}
