#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> x(n), prefsum(n);
    ll sum = 0, total = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i]; sum += x[i];
        prefsum[i] = sum - x[i];
        total += b * x[i];
    }
    ll ans = total;
    for(int i = 0; i < n; i++){
        ll possible_cost = total + x[i] * a - prefsum[i] * b - x[i]*(n-i-1)*b;
        ans = min(ans, possible_cost);
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