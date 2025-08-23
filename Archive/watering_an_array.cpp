#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, k, d; cin >> n >> k >> d;
    vector<int> a(n), v(k);
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == i + 1) cnt++;
    }
    for(int i = 0; i < k; i++) cin >> v[i];
    ll ans = cnt + (d - 1) / 2;
    for(int m = 0; m < min(2*n, d-1); m++){
        int ind = v[m % k];
        for(int j = 0; j < ind; j++){
            if(a[j] == j + 1) cnt--;
            else if(a[j] == j) cnt++;
            a[j]++;
        }
        ll score = cnt + (d - m - 2) / 2;
        ans = max(ans, score);
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