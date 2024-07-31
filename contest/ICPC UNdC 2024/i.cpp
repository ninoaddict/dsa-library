#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
// t1
#define gc getchar_unlocked
#define pii pair<long long, long long>
using ll = long long;
using cd = complex<double>;

const ll maxN = 3e6 + 10, maxM = 2e6 + 10, MAX = 2e6 + 10;
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

ll pref1[maxN], pref2[maxN];

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

vector<ll> compute_hash(string const& s, ll p, ll m, bool rev = 0) {
    ll hash_value = 0;
    ll p_pow = 1;
    vector<ll> res(s.size());
    int l = 0, r = s.size() - 1, adder = 1;
    if(rev){
        swap(l, r);
        adder = -1;
    }
    for(int i = l; i != r + adder; i += adder) {
        char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        res[i] = hash_value;
    }
    return res;
}

vector<ll> manacher_odd(string s) {
    int n = s.size();
    string t = "";
    for(auto &x: s){
        if(x == '#') t += '#';
        else if(x == 'D') t += 'U';
        else t += 'D';
    }
    ll p1 = 29791, m1 = 1e9 + 7;
    ll p2 = 11111, m2 = 1e9 + 9;
    ll i1 = inverseMod(p1, m1);
    ll i2 = inverseMod(p2, m2);
    pref1[0] = pref2[0] = 1;
    for(int i = 1; i < s.size(); i++){
        pref1[i] = (pref1[i - 1] * i1) % m1;
        pref2[i] = (pref2[i - 1] * i2) % m2;
    }
    vector<ll> p(s.size());
    vector<ll> hs1 = compute_hash(s, p1, m1);
    vector<ll> hs2 = compute_hash(s, p2, m2);
    vector<ll> ht1 = compute_hash(t, p1, m1, 1);
    vector<ll> ht2 = compute_hash(t, p2, m2, 1);
    //cout << s << endl;
    //cout << t << endl;
    for(int i = 0; i < s.size(); i++) {
        if(!i || i == s.size() - 1){
            p[i] = 1;
            continue;
        }
        // salah
        if(i == 1 || i == s.size() - 2){
            p[i] = 2;
            continue;
        }
        ll l = 1, r = min(i, (int)(s.size() - i - 1)), ans = 0;
        //cout << i << " staring" << endl;
        while(l <= r){
            ll mid = (l + r) / 2;
            ll fi = (hs1[mid + i] - hs1[i] + m1) % m1;
            fi = (fi * pref1[i]) % m1;

            ll se = (ht1[i - mid] - ht1[i] + m1) % m1;
            se = (se * pref1[s.size() - i - 1]) % m1;

            ll u = (hs2[mid + i] - hs2[i] + m2) % m2;
            u = (u * pref2[i]) % m2;
            ll v = (ht2[i - mid] - ht2[i] + m2) % m2;
            v = (v * pref2[s.size() - i - 1]) % m2;

            if(u == v && fi == se){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
            //cout << mid << " " << l << " " << r << endl;
        }
        //cout << i << endl;
        p[i] = ans + 1;
    }
    return p;
}

vector<ll> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<ll>(begin(res) + 1, end(res) - 1);
}


void solve(){
    ll n; fastInt(n);
    vector<ll> arr(n);
    for(auto &x: arr) fastInt(x);
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    string s = "";
    for(int i = 1; i < n; i++){
        ll uwu = -1;
        if(arr[i] > arr[i - 1]) uwu = 1;
        if(uwu == -1){
            s += "U";
        }else{
            s += "D";
        }
    }
    vector<ll> res = manacher(s);
    /*
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;*/
    ll ans = 0;
    for(int i = 0; i < res.size(); i++){
        if(i & 1){
            ans += (res[i] - 1) / 2;
            //cout << (res[i] - 1) / 2 << " ";
        }else{
            //cout << "0 ";
            continue;
        }
    }
    //cout << endl;
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
