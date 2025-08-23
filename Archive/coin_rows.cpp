#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    int asum = 0, bsum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        asum += a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans = 1e9 + 5;
    for(int i = 0; i < n; i++){
        asum -= a[i];
        if(i > 0) bsum += b[i-1];
        ans = min(max(asum, bsum), ans);
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