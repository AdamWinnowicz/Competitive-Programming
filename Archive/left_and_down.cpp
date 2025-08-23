#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll a, b, k; cin >> a >> b >> k;
    ll g = __gcd(a, b);
    a /= g; b /= g;
    if(a <= k && b <= k){
        cout << 1 << '\n';
    }
    else{
        cout << 2 << '\n';
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