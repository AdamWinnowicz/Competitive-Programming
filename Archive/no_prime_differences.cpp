#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m; cin >> n >> m;
    vector<vector<int>> ans;
    for(int i = m + 1; i < n * m; i += 2 * m){
        vector<int> row;
        for(int j = i; j < i + m; j++){
            row.push_back(j);
        }
        ans.push_back(row);
    }
    for(int i = 1; i < n * m; i += 2 * m){
        vector<int> row;
        for(int j = i; j < i + m; j++){
            row.push_back(j);
        }
        ans.push_back(row);
    }
    for(int i = 0; i < n; i++){
        vector<int> row = ans[i];
        for(int j = 0; j < m; j++){
            cout << row[j] << (j == m-1 ? "\n" : " ");
        }
    }
    cout << '\n';
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