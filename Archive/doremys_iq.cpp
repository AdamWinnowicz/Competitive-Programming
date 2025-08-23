#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n-1;
    while(l < r){
        int m = l + (r - l) / 2;
        bool possible = true;
        int cq = q;
        for(int i = m; i < n; i++){
            if(a[i] > cq){
                if(cq == 0){
                    possible = false; break;
                }
                cq--;
            }
        }
        if(possible){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    string ans;
    for(int i = 0; i < l; i++){
        if(a[i] <= q) ans += '1';
        else ans += '0';
    }
    for(int i = l; i < n; i++){
        ans += '1';
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