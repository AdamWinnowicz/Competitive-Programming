#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int i,int j,vector<vector<int>>& grid, int n, int m){
    grid[i][j] = 0;
    for(int x = 0; x < 4; x++){
        int ni = i + dy[x];
        int nj = j + dx[x];
        if((0 <= ni && ni < n) && (0 <= nj && nj < m) && grid[ni][nj] == 1){
            dfs(ni,nj,grid,n,m);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<vector<int>>grid(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        for(int j = 0; j < m; j++){
            char c = s[j];
            if(c == '1'){
                grid[i][j] = 1;
            }
        } 
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                answer++;
                dfs(i,j,grid,n,m);
            }
        }
    }
    cout << answer << '\n';

    return 0;
}