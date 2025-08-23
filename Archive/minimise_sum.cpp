#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ind = n;
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]){
            ind = i; break;
        }
    }
    ll ans = a[0] + a[1];
    ll currsum = 0, mn = n+1;
    
    for(int i = 0; i < n-1; i++){
        mn = min(mn, a[i]);
        currsum += mn;
        if(i < ind){
            ans = min(ans, currsum + a[i+1]);
        }
        else{
            ans = min(ans, currsum);
        }
    }
    ll total = 0; mn = n+1;
    for(int i = 0; i < n; i++){
        mn = min(mn, a[i]);
        total += mn;
    }
    ans = min(ans, total);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case ? "Yes\n" : "No\n");
    }

    return 0;
}