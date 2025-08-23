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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    while(a.size() > 1){
        vector<int> b;
        for(int i = 0; i < a.size()-1; i+=2){
            if(abs(a[i] - a[i+1]) > 1){
                cout << -1 << '\n'; return;
            }
            if(a[i] > a[i+1]) ans++;
            b.push_back(max(a[i], a[i+1]) / 2);
        }
        a = b;
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