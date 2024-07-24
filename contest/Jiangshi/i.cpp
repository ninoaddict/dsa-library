#include <bits/stdc++.h>
#define int long long int
using namespace std;

pair<double, double> circumcenter(double x1, double y1, double x2, double y2, double x3, double y3) {
    double D = 2 * (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    
    double Ux = ((pow(x1, 2) + pow(y1, 2)) * (y2 - y3) + 
                 (pow(x2, 2) + pow(y2, 2)) * (y3 - y1) + 
                 (pow(x3, 2) + pow(y3, 2)) * (y1 - y2)) / D;
                 
    double Uy = ((pow(x1, 2) + pow(y1, 2)) * (x3 - x2) + 
                 (pow(x2, 2) + pow(y2, 2)) * (x1 - x3) + 
                 (pow(x3, 2) + pow(y3, 2)) * (x2 - x1)) / D;
                 
    return make_pair(Ux, Uy);
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}