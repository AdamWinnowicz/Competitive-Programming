#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

ll subset_max_sum(vector<int>& b){
    ll mx = -1e18;
    for(int i = 0; i < b.size(); i++) if(b[i] > mx) mx = b[i];
    if(mx < 0) return mx;
    ll ans = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i] > 0) ans += b[i];
    }
    return ans;
}

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> odd, even;
    for(int i = 0; i < n; i+=2) even.push_back(a[i]);
    for(int i = 1; i < n; i+=2) odd.push_back(a[i]);
    cout << max(subset_max_sum(odd), subset_max_sum(even)) << '\n';
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