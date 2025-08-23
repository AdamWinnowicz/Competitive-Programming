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
    ll mx = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    cout << max(mx, (sum + x - 1) / x) << '\n';
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