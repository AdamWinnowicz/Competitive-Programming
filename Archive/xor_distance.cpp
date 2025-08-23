#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll a, b, r; cin >> a >> b >> r;
    if(b > a) swap(a, b);
    ll ans = a - b;
    bool found = false;
    for(int bit = 60; bit > -1; bit--){
        ll x = (1LL << bit);
        if(!found && a & x && !(b & x)){
            found = true; continue;
        }
        if(found){
            if(x <= r && a & x && !(b & x)){
                ans -= 2 * x;
                r -= x;
            }
        }
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