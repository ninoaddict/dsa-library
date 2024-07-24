#include <bits/stdc++.h>
#define int long long int
using namespace std;

void print_point(pair<int, int> point) {
    cout << point.first << ' ' << point.second << ' ';
}

int32_t main() {
    int n;
    cin >> n;

    map<pair<int, int>, int> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[{x, y}]++;
    }

    int ox, oy;
    cin >> ox >> oy;

    pair<int, int> origin = make_pair(ox, oy);

    if (!points[origin]) {
        cout << 0 << '\n';
        return 0;
    }

    // search for points with the same absis
    set<pair<int, int>> absis;

    for (auto point: points) {
        if (point.first.first == origin.first) {
            absis.insert(point.first);
        }
    }

    int res = 0;

    // iterate over absis
    for (auto point1: absis) {
        int len = abs(point1.second - origin.second);
        if (!len) continue;

        // check right side
        pair<int, int> point2 = {origin.first + 2 * len, origin.second};
        pair<int, int> point3 = {point1.first + 2 * len, point1.second};
        if (points.find(point2) != points.end() && points.find(point3) != points.end()) {
            res += points[origin] * points[point1] * points[point2] * points[point3];
        }

        // check left side
        pair<int, int> p2 = {origin.first - 2 * len, origin.second};
        pair<int, int> p3 = {point1.first - 2 * len, point1.second};
        if (p2.first >= 0 && p3.first >= 0 && points.find(p2) != points.end() && points.find(p3) != points.end()) {
            res += points[origin] * points[point1] * points[p2] * points[p3];
        }
    }

    cout << res << '\n';
}