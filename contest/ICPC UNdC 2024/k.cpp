#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector <int> arr(n);
  vector <int> pref(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i) {
      pref[i] = arr[i] + pref[i - 1];
    } else {
      pref[i] = arr[i];
    }
  }

  if (pref[n - 1] < 0) {
    cout << - 1 << '\n';
  } else {
    vector<int> res;
    vector<int> lis(n);

    for (int i = 0; i < n; i++) {
      int x = pref[i];
      if (x < 0) {
        lis[i] = 0;
        continue;
      }

      auto it = upper_bound(res.begin(), res.end(), x);
      if (it == res.end()) {
        res.push_back(x);
        lis[i] = res.size();
      } else {
        *it = x;
        lis[i] = it - res.begin() + 1;
      }
    }

    cout << n - lis[n - 1] << '\n';
  }
}