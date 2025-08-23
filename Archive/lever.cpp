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
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            ans += a[i] - b[i];
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