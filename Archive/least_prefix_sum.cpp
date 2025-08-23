#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, m; cin >> n >> m; m--;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<ll> mxhp;
    ll ans = 0, sum = 0;
    for(int i = m; i > 0; i--){
        mxhp.push(a[i]);
        sum += a[i];
        if(sum > 0){
            ll mx_element = mxhp.top();
            sum -= 2 * mx_element; 
            mxhp.pop(); 
            mxhp.push(-1LL * mx_element);
            ans++;
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> mnhp;
    sum = 0;
    for(int i = m + 1; i < n; i++){
        mnhp.push(a[i]);
        sum += a[i];
        if(sum < 0){
            ll mn_element = mnhp.top();
            sum -= 2 * mn_element;
            mnhp.pop();
            mnhp.push(-1LL * mn_element);
            ans++;
        }
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