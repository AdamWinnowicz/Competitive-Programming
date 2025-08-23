#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, m; cin >> n >> m;
    vector<ll> b(n);
    for(ll& x : b) cin >> x;
    vector<vector<pair<ll,ll>>> adj(n);
    for(int i = 0; i < m; i++){
        ll s, t, w; cin >> s >> t >> w; s--; t--;
        adj[t].push_back({s, w});
    }
    ll l = 0, r = 1e18;
    bool found = false;
    while(l < r){
        ll m = l + (r - l) / 2;
        // cannot carry more than m batteries
        vector<ll> dp(n); //max batteries we can have at each point
        dp[0] = min(m, b[0]);
        for(int i = 1; i < n; i++){
            ll mx = 0;
            for(auto [s, w] : adj[i]){
                if(dp[s] >= w){
                    ll val = min(m, dp[s] + b[i]);
                    mx = max(val, mx);
                }
            }
            dp[i] = mx;
        }
        if(dp[n-1] > 0){
            r = m;
            found = true;
        }
        else{
            l = m + 1;
        }
    }
    if(!found){
        cout << "-1\n";
    }
    else cout << l << '\n';
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