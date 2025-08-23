#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

vector<ll> dp(1e6 + 1);

void test_case(){
    ll n; cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = 1; dp[2] = 5; dp[3] = 10;
    ll len = 3;
    ll currlen = 0;
    for(ll v = 4; v <= 1e6; v++){
        if(currlen == 0){
            dp[v] = dp[v - len + 1] + v * v;
        }
        else if(currlen == len - 1){
            dp[v] = dp[v - len] + v * v;
        }
        else{
            dp[v] = dp[v - len] - dp[v - len - (len - 1) + 1] + dp[v - len + 1] + v * v;
        }
        currlen++;
        if(currlen == len){
            currlen = 0;
            len++;
        }
    }

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}