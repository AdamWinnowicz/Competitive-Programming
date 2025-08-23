#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

ll in_circle(ll r){
    ll upper_corner = 0;
    for(ll y = 0; y <= r; y++){
        ll L = 0, R = 1e6;
        ll best = -1;
        while(L <= R){
            ll x = L + (R - L) / 2;
            if((x * x + y * y) < r * r){
                best = max(best, x);
                L = x + 1;
            }
            else{
                R = x - 1;
            }
        }
        upper_corner += best + 1;
    }
    ll ans = 4 * upper_corner - 4 * r;
    return ans;
}

void test_case(){
    ll r; cin >> r;
    cout << in_circle(r + 1) - in_circle(r) << '\n';
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