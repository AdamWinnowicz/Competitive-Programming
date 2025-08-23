#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void test_case(){
    int n; cin >> n;
    ll px, py, qx, qy; cin >> px >> py >> qx >> qy;
    ll dx = px - qx, dy = py - qy;
    ll d = dx*dx + dy*dy;
    vector<ll> a(n);
    ll sum = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    ll max_dist = max(2*mx - sum, 0LL);
    cout << (max_dist*max_dist <= d && d <= sum*sum ? "Yes\n" : "No\n");

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