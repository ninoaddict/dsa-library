#include <bits/stdc++.h>
using namespace std;

bool possible = false;

int n, m;
bool vis[1001][1001][3][4];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void search(vector<vector<char>> &mat, int dir, int x, int y, int belok) {
    if (belok > 2) return;
    if (possible) return;
    if (mat[x][y] == 'T') {
        possible = true;
        return;
    }
    int curr_x, curr_y;
    for (int i = 0; i < 4; i++) {
        curr_x = dx[i] + x;
        curr_y = dy[i] + y;

        if (curr_x >= 0 && curr_x < n && curr_y >= 0 && curr_y < m && mat[curr_x][curr_y] != '*' && !vis[curr_x][curr_y][belok][i]) {
            vis[curr_x][curr_y][belok][i] = true;
            if (i == dir) {
                search(mat, i, curr_x, curr_y, belok);
            } else {
                search(mat, i, curr_x, curr_y, belok + 1);
            }
        }

        if (possible) return;
    }
}

int main() {
    int x, y;
    cin >> n >> m;

    vector<vector<char>> mat (n, vector <char> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        memset(vis, false, sizeof(vis));
        search(mat, i, x, y, 0);
    }
    
    if (possible) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}