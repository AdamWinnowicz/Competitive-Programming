#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for(int i = 1; i < n; i++){
        auto it = upper_bound(b.begin(), b.end(), a[i-1] + a[i] - 1LL);
        if(it == b.end()){
            if(a[i] < a[i-1]) return false;
            else continue;
        }
        ll best_b = *it;
        if(a[i] >= a[i-1] && a[i] < (best_b - a[i])) continue;
        a[i] = best_b - a[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}