#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

ll count_occurences(ll l, ll r, ll d){
    if(l > r) return 0;
    ll x = (r - l) / d;
    if(l > 0) x++;
    return x;
}

void test_case(){
    ll n, m; cin >> n >> m;
    ll ans = 0;
    for(ll b = 1; b <= m; b++){
        ans += count_occurences((b-1) * b, n, b*b);
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