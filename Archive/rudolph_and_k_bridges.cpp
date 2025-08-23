#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m, k, d; cin >> n >> m >> k >> d;
    vector<ll> rivers(n);
    for(int i = 0; i < n; i++){
        vector<ll> a(m);
        for(int i = 0; i < m; i++) cin >> a[i];
        vector<ll> min_costs(m);
        multiset<ll> prev_d;
        for(int i = 0; i < m; i++){
            if(prev_d.size() > d + 1){
                prev_d.erase(prev_d.find(min_costs[i-d-2]));
            }
            ll mn = (prev_d.empty() ? 0 : *prev_d.begin());
            min_costs[i] = mn + a[i] + 1;
            prev_d.insert(min_costs[i]);
        }
        ll total_cost = min_costs[m-1];
        rivers[i] = total_cost;
    }
    ll sum_cost = 0;
    for(int i = 0; i < k; i++){
        sum_cost += rivers[i];
    }
    ll ans = sum_cost;
    for(int i = k; i < n; i++){
        sum_cost -= rivers[i - k];
        sum_cost += rivers[i];
        ans = min(ans, sum_cost);
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