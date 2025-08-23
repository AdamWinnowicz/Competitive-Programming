#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, k; cin >> n >> k;
    if(k % 2 == 1){
        cout << "NO\n"; return;
    }
    ll max_k = 0;
    for(int i = 1; i <= n; i++){
        max_k += abs((n - i + 1) - i);
    }
    if(k > max_k){
        cout << "NO\n"; return;
    }
    vector<int> ans(n);
    for(int i = 1; i <= n; i++){
        ans[i-1] = i;
    }
    int l = 0, r = n-1;
    while(l < r && k > 0){
        int gain = abs(ans[r] - (l + 1)) + abs(ans[l] - (r + 1));
        if(gain <= k){
            swap(ans[l],ans[r]);
            k -= gain;
            l++; r--;
        }
        else{
            r--;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "\n" : " ");
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