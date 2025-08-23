#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m, x; cin >> n >> x >> m;
    int L = x, R = x;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        if(l <= L && r >= R){
            L = l; R = r;
        }
        else if(l <= L && r >= L){
            L = l;
        }
        else if(r >= R && l <= R){
            R = r;
        }
    }
    cout << R - L + 1 << '\n';
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