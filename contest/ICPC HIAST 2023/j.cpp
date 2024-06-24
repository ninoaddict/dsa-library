#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
// t1
#define gc _getchar_nolock
#define pii pair<long long, long long>
using ll = long long;
using cd = complex<double>;

const ll maxN = 2e6 + 10, maxM = 1e6, MAX = 2e6 + 10;
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
const int LOGN = 23;
const int num1 = 16;
const int INF = 1e9;
//const ll is_query = -(1LL<<62);

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

/*
ll querySum(ll ind, ll l, ll r, ll tl, ll tr){
    if(r < tl || tr < l) return 0;
    if(tl <= l && r <= tr) return seg[ind][1];
    ll mid = (l + r) >> 1;
    return querySum(ind << 1, l, mid, tl, tr) + querySum(ind << 1 | 1, mid + 1, r, tl, tr);
}

ll queryIndex(ll ind, ll l, ll r, ll i, ll sum){
    if(seg[ind][1] == 0) return -1;
    if(l == r){
        return l;
    }
    ll mid = (l + r) >> 1;
    ll l1 = l, r1 = mid;
    ll l2 = mid + 1, r2 = r;
    if(i >= l2 && i <= r2){
        return queryIndex(ind << 1 | 1, l2, r2, i, sum - seg[ind << 1][1]);
    }
    if(seg[ind << 1][1] > 0){
        if(seg[ind << 1][1] > sum){
            return queryIndex(ind << 1, l1, r1, i, sum);
        }else{
            assert(seg[ind << 1][1] >= sum);
            return queryIndex(ind << 1 | 1, l2, r2, i, 0);
        }
    }else{
        return queryIndex(ind << 1 | 1, l2, r2, i, sum - seg[ind << 1][1]);
    }
}*/


void solve(){
    ll n, sum = 0;
    fastInt(n);
    vector<ll> arr(n);
    for(auto &x: arr){
        fastInt(x);
        sum += x;
    }
    if(n == 1){
        cout << arr[0] << '\n';
        return;
    }
    sort(arr.begin(), arr.end());
    if(n & 1){
        ll indmed = ((n + 1) >> 1) - 1;
        ll med = arr[indmed];
        ll kirimed = arr[indmed - 1];
        if(kirimed * n + kirimed - sum <= kirimed){
            cout << kirimed * n + kirimed - sum << '\n';
            return;
        }
        if(med * n + med - sum >= med){
            cout << med * n + med - sum << '\n';
            return;
        }
        ll x = sum / n;
        assert(x > kirimed && x < med);
        cout << sum / n << '\n';
    }else{
        ll indmed = ((n + 1) >> 1) - 1;
        ll med = arr[indmed];
        ll kananmed = arr[indmed + 1];
        if(med * n + med - sum <= med){
            cout << med * n + med - sum << '\n';
            return;
        }
        if(kananmed * n + kananmed - sum >= kananmed){
            cout << kananmed * n + kananmed - sum << '\n';
            return;
        }
        ll x = sum / n;
        assert(x > med && x < kananmed);
        cout << sum / n << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //auto beg = high_resolution_clock::now();
    //precalc();
    //cout << req(1e7 + 8) << '\n';
    int t; fastInt(t);
    while(t--) solve();
    //auto en = high_resolution_clock::now();
    //auto dur = duration_cast<microseconds>(en - beg);
    //cout << dur.count() << endl;
    return 0;
}