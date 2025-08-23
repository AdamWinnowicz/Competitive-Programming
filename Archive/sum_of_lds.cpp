#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1;
    vector<ll> dp(n + 1);
    dp[n-1] = 1;
    for (int i = n-2; i > -1; i--){
        if(a[i] > a[i+1]){
            dp[i] = dp[i+1] + n - i;
        }
        else{
            dp[i] = dp[i+2] + n - i;
        }
        ans += dp[i];
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        test_case();
        // cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}