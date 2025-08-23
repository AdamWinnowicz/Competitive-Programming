#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0;
    vector<ll> prefsum(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        prefsum[i] = sum;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll right = sum - prefsum[i];
        ll total = right + abs(prefsum[i]);
        ans = max(ans, total);
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