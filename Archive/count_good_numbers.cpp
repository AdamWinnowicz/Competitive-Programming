#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

ll cnt(ll x) {
    ll ans = x;
    ans -= x/2;
    ans -= x/3;
    ans -= x/5;
    ans -= x/7;
    ans += x/(2*3);
    ans += x/(2*5);
    ans += x/(2*7);
    ans += x/(3*5);
    ans += x/(3*7);
    ans += x/(5*7);
    ans -= x/(2*3*5);
    ans -= x/(2*3*7);
    ans -= x/(2*5*7);
    ans -= x/(3*5*7);
    ans += x/(2*3*5*7);
    return ans;
}

void test_case(){
    ll l, r; cin >> l >> r;
    cout << cnt(r) - cnt(l-1) << '\n';
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