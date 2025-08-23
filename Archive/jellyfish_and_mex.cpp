#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const ll MAX = 1e9 + 5;

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    vector<bool> there(n + 1);
    map<ll,ll> cnt;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(a[i] <= n) there[a[i]] = true;
    }
    ll MEX = -1;
    for(int i = 0; i <= n; i++){
        if(!there[i]){
            MEX = i;
            break;
        }
    }
    ll dp[MEX + 1];
    fill(dp, dp + MEX + 1, MAX);
    dp[MEX] = 0;
    for(int i = MEX - 1; i > -1; i--){
        for(int j = MEX; j > i; j--){
            dp[i] = min(dp[i], dp[j] + (cnt[i] - 1) * j + i);
        }
    }
    cout << dp[0] << '\n';
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