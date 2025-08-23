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
    for(int i = 0; i < n; i++) cin >> a[i];
    // make this 2D prefix sums so we can quickly get the smaller in a prev range and the larger in an after range
    vector<vector<ll>> info(n, vector<ll>(n));
    // prev[i][j] = the number of elements in prefix up to j that are less than a[i]
    // after[i][j] = the number of elements in suffix starting at j that are greater than a[i]
    for(int i = 0; i < n; i++){
        ll prev_sum = 0, after_sum = 0;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]) prev_sum++;
            info[i][j] = prev_sum;
        }
        for(int j = n-1; j > i; j--){
            if(a[j] < a[i]) after_sum++;
            info[i][j] = after_sum;
        }
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n - 1; j++){
            // first find how many are larger than a[i] in suffix starting from j + 1
            ll larger = info[i][j + 1];
            // then find how many are smaller than a[j] in prefix ending at i - 1
            ll smaller = info[j][i-1];
            ans += larger * smaller;
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