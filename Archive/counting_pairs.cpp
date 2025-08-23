#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += upper_bound(a.begin() + i + 1, a.end(), total - a[i] - x) - lower_bound(a.begin() + i + 1, a.end(), total - a[i] - y);
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