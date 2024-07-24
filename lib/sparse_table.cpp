#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
const int K = 25;
int st[K + 1][MAXN];

void preprocess(vector <int> a, int n) {
    for (int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
            // for min range
            // st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

// range sum queries
int range_sum(int L, int R) {
    int sum = 0;
    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= R - L + 1) {
            sum += st[i][L];
            L += 1 << i;
        }
    }
    return sum;
}

// range minimum queries
int range_min(int L, int R) {
    int i = (int)log2(R - L + 1);
    return min(st[i][L], st[i][R - (1 << i) + 1]);
}