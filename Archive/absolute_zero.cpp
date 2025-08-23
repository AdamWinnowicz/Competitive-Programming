#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    bool even = false, odd = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) even = true;
        else odd = true;
    }
    if(even && odd){
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    int mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
    while(mx != mn){
        ans.push_back(mx / 2);
        for(int i = 0; i < n; i++){
            a[i] = abs(a[i] - mx / 2);
        }
        mx = *max_element(a.begin(), a.end()); mn = *min_element(a.begin(), a.end());
    }
    if(mx > 0){
        ans.push_back(mx);
    }
    int len = ans.size();
    cout << len << '\n';
    if(ans.size() == 0){
        cout << '\n';
    }
    else{
        for(int i = 0; i < len; i++){
            cout << ans[i] << (i == len-1 ? "\n" : " ");
        }
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