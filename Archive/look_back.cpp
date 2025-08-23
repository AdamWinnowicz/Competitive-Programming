#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto& x : a)
        cin >> x;
    ll ans = 0;
    ll shift = 0;
    for(int i = 1; i < n; i++){
        ll diff = __builtin_clzll(a[i]) - (__builtin_clzll(a[i-1]) - shift);
        if(diff < 0){
            shift = 0;
            continue;
        }
        string x, y;
        for(int b = 30; b > -1; b--){
            if(a[i] & (1 << b)) y += '1';
            else if(y.length() > 0) y += '0';
            if(a[i - 1] & (1 << b)) x += '1';
            else if(x.length() > 0) x += '0';
        }
        while(x.length() < y.length()) x += '0';
        while(y.length() < x.length()) y += '0';
        bool needs_extra = false;
        for(int i = 0; i < x.length(); i++){
            if(x[i] == '0' && y[i] == '1') break;
            if(x[i] == '1' && y[i] == '0'){
                needs_extra = true;
                break;
            }
        }
        if(needs_extra) diff++;
        ans += diff;
        shift = diff;
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