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

vector<pii> hardcoded = {
    {6, 9},
    {3, 14}
};

vector<ll> compat = {
    0, 1, 2, 5, 8
};

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

ll figure_out(ll a, ll b){
    if(a == b){
        bool ok = 0;
        for(auto &x: compat){
            if(x == a) ok = 1;
        }
        if(ok) return 0;
    }
    bool ok = 0, okhalf = 0;
    for(auto &x: hardcoded){
        if(x.first == a && x.second == b){
            ok = 1;
        }
        if(x.first == b && x.second == a){
            ok = 1;
        }
        if(x.first == b || x.first == a || x.second == b || x.second == a){
            okhalf = 1;
        }
    }
    for(auto &x: compat){
        if(x == a || x == b) okhalf = 1;
    }
    if(ok) return 0;
    if(okhalf) return 1;
    return 2;
}

void solve(){
    string s;
    fastStr(s);
    ll ans = 0;
    for (auto &c: s) c = toupper(c);
    for(int i = 0; i < s.size(); i++){
        if(i > s.size() - i - 1) break;
        int u = s[i] - '0';
        if(u >= (int)('A' - '0')){
            u -= (int)('A' - '0');
            u += 10;
        }
        int cprime = s.size() - i - 1;
        if(cprime == i){
            bool ok = 0;
            for(auto &x: compat){
                if(x == u) ok = 1;
            }
            if(ok) continue;
            ans++;
            continue;
        }
        int u2 = s[cprime] - '0';
        if(u2 >= (int)('A' - '0')){
            u2 -= (int)('A' - '0');
            u2 += 10;
        }
        //cout << i << " " << u << " " << u2 << endl;
        ans += figure_out(u, u2);
    }
    cout << ans << '\n';
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
