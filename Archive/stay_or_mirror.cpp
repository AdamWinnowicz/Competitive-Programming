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
    int ans = 0;
    for(int v = 1; v <= n; v++){
        int ind = -1;
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == v){
                ind = i;
            }
            else if(a[i] > v && a[i] < (2*n - v)){
                if(ind == -1) l++;
                else r++;
            }
        }
        ans += min(l, r);
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