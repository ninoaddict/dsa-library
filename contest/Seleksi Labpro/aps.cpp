#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll res = 0;

class BinaryTree {
    public:
        ll node;
        BinaryTree *left;
        BinaryTree *right;

        BinaryTree(): node(0), left(nullptr), right(nullptr) {}
        BinaryTree(ll node_num): node(node_num), left(nullptr), right(nullptr) {}
        BinaryTree(ll node_num, BinaryTree *left_tree, BinaryTree *right_tree): node(node_num), left(left_tree), right(right_tree) {}
};

void dfs(BinaryTree * v, bool is_left, ll curr_len) {
    if (!v) return;
    res = max(res, curr_len);
    if (is_left) {
        dfs(v->left, false, curr_len + 1);
        dfs(v->right, true, 1);
    }
    else {
        dfs(v->right, true, curr_len + 1);
        dfs(v->left, false, 1);
    }
}

int main() {
    ll n;
    cin >> n;

    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BinaryTree * root = new BinaryTree(arr[0]);
    queue <BinaryTree*> q;
    q.push(root);

    int idx = 1;

    while (!q.empty()) {
        BinaryTree * fr = q.front();
        q.pop();

        if (idx >= n) break;

        ll l = arr[idx];
        idx++;
        ll r = arr[idx];
        idx++;
        
        if (l != -1) {
            BinaryTree * left = new BinaryTree(l);
            fr->left = left;
            q.push(left);
        }

        if (r != -1) {
            BinaryTree * right = new BinaryTree(r);
            fr->right = right;
            q.push(right);
        }
    }

    dfs(root, true, 0);
    dfs(root, false, 0);

    cout << res << '\n';
}