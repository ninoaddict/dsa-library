#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define gc _getchar_nolock
#define pii pair<long long, long long>
using ll = long long;

const ll maxN = 1e7, maxM = 1e6 + 10, MAX = 1e7;
const ll maxScore = 4294967295;
const ll mod = 1e18;
const double pi = acos(-1.0);
const double e = exp(1.0);
const ll naught = -100001;
const ll maxT = ceil(sqrt(maxN)) + 1;
const ll root = 15311432;
const ll root_1 = 469870224;
const ll root_pw = (1 << 23);
const int K = 19;
const int g = 3;
const int LOGN = 23;
const int num1 = 16;

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
    ll x; fastInt(x);
    vector<string> v;
    string base = "";
    string s;
    for(int i = 1; i <= x; ++i){
        fastStr(s);
        if(i == 1) base = s;
        v.push_back(s);
    }
    ll g; fastInt(g);
    vector<string> guesses;
    for(int i = 1; i <= g; ++i){
        fastStr(s);
        guesses.push_back(s);
    }
    for(int i = 0; i < g; ++i){
        int cnt = 0;
        for(int j = 0; j < x; ++j){
            bool ok = 1;
            for(int k = 0; k < 5 && ok; ++k){
                if(v[j][k] == base[k] && guesses[i][k] != '*') ok = 0;
                if(guesses[i][k] == '*' && v[j][k] != base[k]) ok = 0;
            }
            if(!ok) continue;
            int defex = 0;
            for(int k = 0; k < 5; ++k){
                defex |= (1 << (base[k] - 'a'));
            }
            int allex = (1 << 26) - 1;
            allex ^= defex;
            int notex = 0, ex = 0;
            for(int k = 0; k < 5 && ok; ++k){
                if(guesses[i][k] == 'X' && (defex & (1 << (v[j][k] - 'a')))) ok = 0;
                else if(guesses[i][k] == '!' && !(defex & (1 << (v[j][k] - 'a')))) ok = 0;
            }
            if(ok) cnt++;
        }
        cout << cnt << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    auto beg = high_resolution_clock::now();
    //precalc();
    int t; t = 1;
    while(t--) solve();
    auto en = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(en - beg);
    //cout << dur.count() << endl;
    return 0;
}