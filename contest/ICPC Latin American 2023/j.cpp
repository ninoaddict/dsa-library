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
const int INF = 1e9;

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

vector<vector<int>> adj;
vector<int> subtree_size;
vector<int> min_dist;
vector<bool> is_removed;
vector<vector<pair<int, int>>> ancestors;
vector<int> ans;

int get_subtree_size(int node, int parent = -1) {
	subtree_size[node] = 1;
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		subtree_size[node] += get_subtree_size(child, node);
	}
	return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		if (subtree_size[child] * 2 > tree_size) {
			return get_centroid(child, tree_size, node);
		}
	}
	return node;
}

void get_dists(int node, int centroid, int parent = -1, int cur_dist = 1) {
	for (int child : adj[node]) {
		if (child == parent || is_removed[child]) { continue; }
		cur_dist++;
		get_dists(child, centroid, node, cur_dist);
		cur_dist--;
	}
	ancestors[node].push_back({centroid, cur_dist});
}

void build_centroid_decomp(int node = 0) {
	int centroid = get_centroid(node, get_subtree_size(node));
	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		get_dists(child, centroid, centroid);
	}
	is_removed[centroid] = true;
	for (int child : adj[centroid]) {
		if (is_removed[child]) { continue; }
		build_centroid_decomp(child);
	}
}

void paint(int node) {
	for (auto &[ancestor, dist] : ancestors[node]) {
        if(min_dist[ancestor] > dist){
            //if(t) cout << ancestor << endl;
            min_dist[ancestor] = min(min_dist[ancestor], dist);
            ans[ancestor] = node;
        }else if(min_dist[ancestor] == dist){
            if(ans[ancestor] == -1) ans[ancestor] = node;
            else ans[ancestor] = min(ans[ancestor], node);
        }
	}
	min_dist[node] = 0;
	ans[node] = node;
}

int query(int node) {
	int cur = min_dist[node];
	int res = ans[node];
	for (auto &p : ancestors[node]) {
        int ancestor = p.first;
        int dist = p.second;
		//if(t) cout << ancestor << " kntl " << endl;
        if(cur > dist + min_dist[ancestor]){
            cur = dist + min_dist[ancestor];
            res = ans[ancestor];
        }else if(cur == dist + min_dist[ancestor]){
            if(res == -1) res = ans[ancestor];
            else res = min(res, ans[ancestor]);
        }
	}
	assert(cur != INT_MAX);
	return res;
}

void solvemain() {
	int N;
	fastInt(N);
	adj.assign(N, vector<int>());
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		fastInt(a); fastInt(b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    ans.assign(N, -1);
	subtree_size.assign(N, 0);
	ancestors.assign(N, vector<pair<int, int>>());
	is_removed.assign(N, false);
	build_centroid_decomp();

	min_dist.assign(N, INF);
	paint(N - 1);
	vector<int> v;
	for (int i = N - 2; i >= 0; --i) {
        int ans = query(i);
        assert(ans != -1);
        v.push_back(ans);
        paint(i);
	}
	reverse(v.begin(), v.end());
	for(auto &x: v){
        cout << x + 1 << " ";
	}
	cout << N << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    auto beg = high_resolution_clock::now();
    //precalc();
    int t; t = 1;
    while(t--) solvemain();
    auto en = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(en - beg);
    //cout << dur.count() << endl;
    return 0;
}