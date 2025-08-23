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
    ll altsum = 0;
    set<ll> seen = {0};
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            altsum += a[i];
        }
        else altsum -= a[i];
        if(seen.find(altsum) != seen.end()){
            return true;
        }
        seen.insert(altsum);
    }
    return false;
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