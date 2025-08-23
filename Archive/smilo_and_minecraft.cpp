#include <bits/stdc++.h>
using namespace std;

int count(int i1, int j1, int i2, int j2, vector<vector<int>> &pref){
    int n = pref.size(), m = pref[0].size();
    int topsum = 0, leftsum = 0, intersect = 0;
    if(0 <= i1-1 && i1-1 <= n-1) topsum = pref[i1-1][j2];
    if(0 <= j1-1 && j1-1 <= m-1) leftsum = pref[i2][j1-1];
    if(0 <= i1-1 && i1-1 <= n-1 && 0 <= j1-1 && j1-1 <= m-1) intersect = pref[i1-1][j1-1];
    return pref[i2][j2] - topsum - leftsum + intersect;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        vector<string> mine;
        for(int i = 0; i < n; i++){
            string row; cin >> row;
            mine.push_back(row);
        }
        int gold = 0;
        vector<vector<int>> pref(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int topsum = 0, leftsum = 0, intersect = 0;
                if(0 <= i-1 && i-1 <= n-1) topsum = pref[i-1][j];
                if(0 <= j-1 && j-1 <= m-1) leftsum = pref[i][j-1];
                if((0 <= j-1 && j-1 <= m-1) && (0 <= i-1 && i-1 <= n-1)) intersect = pref[i-1][j-1];
                int val = (mine[i][j] == 'g' ? 1 : 0);
                if(mine[i][j] == 'g') gold++;
                pref[i][j] = val + topsum + leftsum - intersect;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mine[i][j] == '.'){
                    int ti = i+k-1, tj = j+k-1;
                    if(!(0 <= ti && ti <= n-1)) ti = n-1;
                    if(!(0 <= tj && tj <= m-1)) tj = m-1;
                    ans = max(ans, gold - count(i-k+1,j-k+1,ti,tj,pref));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}