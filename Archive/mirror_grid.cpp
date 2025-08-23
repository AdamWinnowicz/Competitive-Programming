#include <bits/stdc++.h>
using namespace std;
#define ll long long

int four_corners_count(int i, int j, vector<string>& grid, int n){
    int count = 0;
    if(grid[i][j] == '1') count++;
    if(grid[j][n - i - 1] == '1') count++;
    if(grid[n - j - 1][i] == '1') count++;
    if(grid[n - i - 1][n - j - 1] == '1') count++;
    grid[i][j] = grid[j][n - i - 1] = grid[n - j - 1][i] = grid[n - i - 1][n - j - 1] = '1';
    return min(count, 4 - count);
}

void test_case(){
    int n; cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int ans = 0;
    for(int i = 0; i < (n + 1) / 2; i++){
        for(int j = 0; j < (n + 1) / 2; j++){
            ans += four_corners_count(i, j, grid, n);
        }
    }
    cout << ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}