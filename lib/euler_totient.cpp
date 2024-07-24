#include <bits/stdc++.h>
using namespace std;

// implementation in O(sqrt(N))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// euler totient function from 1 to N in O(n log log n)
vector<int> phi_1_to_n(int n) {
    vector<int> ph(n + 1);
    for (int i = 0; i <= n; i++)
        ph[i] = i;

    for (int i = 2; i <= n; i++) {
        if (ph[i] == i) {
            for (int j = i; j <= n; j += i)
                ph[j] -= ph[j] / i;
        }
    }
    return ph;
}