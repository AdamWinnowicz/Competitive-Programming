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
    int mn = 1e9 + 5;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    cout << n - 1 << '\n';
    int loc = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == mn){
            loc = i;
            break;
        }
    }
    bool minplusone = true;
    for(int i = loc; i > 0; i--){
        if(minplusone) a[i-1] = mn + 1;
        else a[i-1] = mn; minplusone = !minplusone;
        cout << i << ' ' << loc+1 << ' ' << a[i-1] << ' ' << mn << '\n';
    }
    minplusone = true;
    for(int i = loc; i < n-1; i++){
        if(minplusone) a[i+1] = mn + 1;
        else a[i+1] = mn; minplusone = !minplusone;
        cout << loc+1 << ' ' << i + 2  << ' ' << mn << ' ' << a[i+1] << '\n';
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