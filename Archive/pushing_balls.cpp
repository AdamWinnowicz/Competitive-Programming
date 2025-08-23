#include <bits/stdc++.h>
using namespace std;

bool check(int r, int c, vector<string> g){
    bool upcheck = true, leftcheck = true;
    for(int j = 0; j < c; j++){
        if(g[r][j] == '0'){
            leftcheck = false;
            break;
        } 
    }
    for(int i = 0; i < r; i++){
        if(g[i][c] == '0'){
            upcheck = false;
            break;
        }
    }
    return leftcheck || upcheck;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<string> grid;
        for(int i = 0; i < n; i++){
            string row; cin >> row;
            grid.push_back(row);
        }
        bool possible = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    if(!check(i,j,grid)){
                        possible = false;
                        break;
                    }
                }
            }
        }
        if(possible){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    

    return 0;
}