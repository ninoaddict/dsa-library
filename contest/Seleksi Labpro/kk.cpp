#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue <int> pq;
    for (int i = 0; i < n; i++) {
        int elmt;
        cin >> elmt;
        pq.push(elmt);
    }

    k--;
    while (k--) {
        pq.pop();
    }
    cout << pq.top() << '\n';
}