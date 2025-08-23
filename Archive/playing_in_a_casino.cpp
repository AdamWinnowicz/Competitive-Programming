#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(m, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[j][i];
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        sort(g[i].begin(), g[i].end());
        ll sum = accumulate(g[i].begin(), g[i].end(), 0LL);
        ll prev = 0;
        for(int j = 0; j < n; j++){
            sum -= (n-j) * (g[i][j]-prev);
            ans += sum;
            prev = g[i][j];
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