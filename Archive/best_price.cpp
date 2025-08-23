#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    set<ll> prices;
    for(int i = 0; i < n; i++){
        cin >> a[i]; prices.insert(a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i]; prices.insert(b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for(ll p : prices){
        ll trees_bought = b.end() - lower_bound(b.begin(), b.end(), p);
        ll negative_reviews = trees_bought - (a.end() - lower_bound(a.begin(), a.end(), p));
        if(negative_reviews <= k){
            ans = max(ans, trees_bought * p);
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
    }

    return 0;
}