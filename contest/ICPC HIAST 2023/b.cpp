#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define gc _getchar_nolock
#define pii pair<long long, long long>
using ll = long long;
using cd = complex<double>;

const ll maxN = 2e6 + 10, maxM = 1e6, MAX = 2e6 + 10;
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

int pr[MAX];

int st[K + 1][maxN];

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

struct cmp{
    bool operator()(pii &p1, pii &p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

void solve(){
    int n, q;
    fastInt(n); fastInt(q);
    vector<int> arr(n);
    priority_queue<pii, vector<pii>, cmp> pq;
    int i = 0;
    for(auto &x: arr){
        fastInt(x);
        if(x != 1) pq.push({x, i});
        i++;
    }
    vector<int> timer(n, 0);
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            timer[i] = 0;
        }
    }
    int t = 1;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        int val = u.first;
        val /= pr[val];
        if(val == 1){
            timer[u.second] = t;
        }else{
            pq.push({val, u.second});
        }
        t++;
    }
    std::copy(timer.begin(), timer.end(), st[0]);
    for (int i = 1; i <= K; i++){
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    for(int i = 1; i <= q; i++){
        int l, r;
        fastInt(l); fastInt(r);
        l--; r--;
        int u = floor(log2((r - l + 1) * 1.0));
        int maxi = max(st[u][l], st[u][r - (1 << u) + 1]);
        cout << maxi << '\n';
    }
    /*
    for(int i = 0; i < n; i++){
        cout << timer[i] << " ";
    }*/
}

void precalc(){
    for(int i = 2; i < MAX; i++) pr[i] = i;
    for (int i = 2; i < MAX; i++) {
        if (pr[i] == i) {
            for (int j = 2 * i; j < MAX; j += i)
                pr[j] = i;
        }
    }

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //auto beg = high_resolution_clock::now();
    precalc();
    //cout << req(1e7 + 8) << '\n';
    int t; t = 1;
    while(t--) solve();
    //auto en = high_resolution_clock::now();
    //auto dur = duration_cast<microseconds>(en - beg);
    //cout << dur.count() << endl;
    return 0;
}