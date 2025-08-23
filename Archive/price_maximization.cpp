#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void test_case(){
    ll n, k; cin >> n >> k;
    vector<ll> a;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll v; cin >> v; ans += (v / k);
        a.push_back(v % k);
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n-1;
    while(l < r){
        if(a[l] + a[r] >= k){
            ans++; l++; r--;
        }
        else l++;
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        test_case();
    }
 
    return 0;
}