#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    vector<vector<int>> hor(h, vector<int>(w));
    vector<vector<int>> ver(h, vector<int>(w));

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j){
            if (grid[i][j] == '#') continue;
            if (j + 1 < w && grid[i][j+1] != '#') hor[i][j] = 1;
            if (i + 1 < w && grid[i+1][j] != '#') ver[i][j] = 1;
        }

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j){
            if (i > 0){
                ver[i][j] += ver[i-1][j];
                hor[i][j] += hor[i-1][j];
            }
            if (j > 0){
                ver[i][j] += ver[i][j-1];
                hor[i][j] += hor[i][j-1];
            }
            if (i > 0 && j > 0){
                ver[i][j] -= ver[i-1][j-1];
                hor[i][j] -= hor[i-1][j-1];
            }
        }

    auto f = [](const vector<vector<int>> &M, int r1, int c1, int r2, int c2){
        if (r1 > r2 || c1 > c2) return 0;
        int sol = M[r2][c2];
        if (r1 > 0) sol -= M[r1-1][c2];
        if (c1 > 0) sol -= M[r2][c1-1];
        if (r1 > 0 && c1 > 0) sol += M[r1-1][c1-1];
        return sol;
    };    
    
    int q; cin >> q;
    while (q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; r2--; c1--; c2--;
        int sol = 0;
        sol += f(hor, r1, c1, r2, c2);
        sol += f(ver, r1, c1, r2, c2);
        cout << sol << endl;
    }

    return 0;
}