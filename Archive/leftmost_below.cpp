#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mn = a[0];
    for(int i = 1; i < n; i++){
        ll upper_b = 2*mn - 1;
        if(a[i] > upper_b) return false;
        mn = min(mn, a[i]);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}