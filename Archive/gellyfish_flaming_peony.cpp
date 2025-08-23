#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> GCD(5005, vector<int>(5005));
    for(int i = 0; i < 5005; i++){
        GCD[i][i] = i; GCD[i][0] = i; GCD[0][i] = i;
    }
    for(int i = 2; i < 5005; i++){
        for(int j = 1; j < i; j++){
            GCD[i][j] = GCD[j][i%j];
            GCD[j][i] = GCD[i][j];
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        int g = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i]; g = GCD[a[i]][g];
        }
        int cnt = count(a.begin(), a.end(), g);
        if(cnt){
            cout << n - cnt << '\n'; continue;
        }
        vector<int> dp(5050,10000);
        for(int i = 0; i < n; i++) dp[a[i]] = 0;
        for(int i = 0; i < n; i++){
            for(int x = 1; x <= 5000; x++){
                int k = GCD[a[i]][x];
                dp[k] = min(dp[k],dp[x]+1);
            }
        }
        cout << dp[g]+n-1 << '\n';
        
    }

    return 0;
}