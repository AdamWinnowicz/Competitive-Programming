#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    ll ans = 0;
    for(int b = 0; b <= 30; b++){
        string s;
        for(int x : a){
            if(x & (1 << b)) s += '1';
            else s += '0';
        }
        vector<ll> dp(n), dp2(n), dp3(n), dp4(n);
        dp[0] = (s[0] == '1' ? 1 : 0);
        dp2[0] = (s[0] == '1' ? 0 : 1);
        dp3[0] = (s[0] == '1' ? 1 : 0);
        dp4[0] = (s[0] == '1' ? 0 : 1);
        for(int i = 1; i < n; i++){
            if(s[i] == '1'){
                dp[i] = (dp2[i-1] + 1) % MOD;
                dp2[i] = dp[i-1] % MOD;
                dp3[i] = ((dp4[i-1] % MOD) + (dp2[i-1] % MOD) + 1) % MOD;
                dp4[i] = ((dp3[i-1] % MOD) + (dp[i-1] % MOD)) % MOD;
            }
            else{
                dp[i] = dp[i-1] % MOD;
                dp2[i] = (dp2[i-1] + 1) % MOD;
                dp3[i] = ((dp3[i-1] % MOD) + (dp[i-1] % MOD)) % MOD;
                dp4[i] = ((dp4[i-1] % MOD) + (dp2[i-1] % MOD) + 1) % MOD;
            }
        }
        ll total = 0;
        for(int i = 0; i < n; i++){
            total = (total + dp3[i]) % MOD;
        }
        ll bit_value = (1 << b) % MOD;
        ans = ((bit_value * total) % MOD + ans) % MOD;
    }
    cout << ans << '\n';

    return 0;
}