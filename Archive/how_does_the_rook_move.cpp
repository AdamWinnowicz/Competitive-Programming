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
    int rc_left = n;
    for(int i = 0; i < k; i++){
        int r, c; cin >> r >> c;
        if(r == c) rc_left--;
        else rc_left -= 2;
    }
    ll dp[rc_left + 1];
    dp[0] = 1; if(rc_left > 0) dp[1] = 1;
    for(int i = 2; i <= rc_left; i++){
        dp[i] = ((dp[i-2] * (2*i - 2)) % MOD + dp[i-1]) % MOD;
    }
    cout << dp[rc_left] << '\n';
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