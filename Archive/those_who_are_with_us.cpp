#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> grid;
        int mx = 0;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < m; j++){
                int val; cin >> val;
                row.push_back(val);
                mx = max(mx, val);
            }
            grid.push_back(row);
        }
        int used = 0;
        bool row = false, col = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == mx){
                    grid[i][j]--;
                    bool none = true;
                    if(!row){
                        for(int j2 = 0; j2 < m; j2++){
                            if(j != j2 && grid[i][j2] == mx){
                                grid[i][j2]--;
                                row = true;
                            }
                        }
                        if(row) {used++; none = false;}
                    }
                    if(!col){
                        for(int i2 = 0; i2 < n; i2++){
                            if(i != i2 && grid[i2][j] == mx){
                                grid[i2][j]--;
                                col = true;
                            }
                        }
                        if(col) {used++; none = false;}
                    }
                    if(none) used++;
                }
            }
        }

        if(used > 2){
            cout << mx << '\n';
        }
        else{
            cout << mx - 1 << '\n';
        }
        
    }

    return 0;
}