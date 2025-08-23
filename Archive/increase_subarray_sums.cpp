#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(n + 1, -1e18);
    b[0] = 0;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            ll w = j - i + 1;
            sum += a[j];
            b[w] = max(b[w], sum);
        }
    }
    for(ll k = 0; k <= n; k++){
        ll best = 0;
        for(ll len = 0; len <= n; len++){
            ll val = b[len] + min(k, len) * x;
            best = max(best, val);
        }
        cout << best << (k == n ? "\n" : " ");
    }

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