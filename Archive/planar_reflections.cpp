#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const ll MOD = 1e9 + 7;

void test_case(){
    int n, k; cin >> n >> k;
    // shooting from index i with strength x and direction 0 (right) or 1 (left)
    ll dp[n + 1][k + 1][2];
    for(int i = 0; i <= n; i++){
        for(int x = 1; x <= k; x++){
            for(int d = 0; d < 2; d++){
                dp[i][x][d] = 1;
            }
        }
    }
    vector<ll> pref_right(n+1), pref_left(n+1);
    ll sum_right = 0, sum_left = 0;
    for(int i = 0; i <= n; i++){
        sum_right = (sum_right + dp[i][1][0]) % MOD;
        pref_right[i] = sum_right;
        sum_left = (sum_left + dp[i][1][1]) % MOD;
        pref_left[i] = sum_left; 
    }
    for(int x = 2; x <= k; x++){
        for(int i = 0; i <= n; i++){
            dp[i][x][0] = ((pref_left[n] - pref_left[i] + MOD) % MOD + 1LL) % MOD;
            if(i > 0) dp[i][x][1] = ((pref_right[i-1] - pref_right[0] + MOD) % MOD + 1LL) % MOD;
        }
        sum_right = 0; sum_left = 0;
        for(int i = 0; i <= n; i++){
            sum_right = (sum_right + dp[i][x][0]) % MOD;
            pref_right[i] = sum_right;
            sum_left = (sum_left + dp[i][x][1]) % MOD;
            pref_left[i] = sum_left; 
        }
    }
    cout << dp[0][k][0] << '\n';
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