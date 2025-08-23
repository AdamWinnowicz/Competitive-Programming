#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> a(n);
    // ll mn = 1e9 + 5;
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    //     mn = min(mn, a[i]);
    // }
    // ll d = a[1] - a[0];
    // bool possible = true;
    // for(int i = 2; i < n; i++){
    //     if(a[i] - a[i-1] != d){
    //         possible = false; break;
    //     }
    // }
    // if(mn < abs(d)) possible = false;
    // else if(mn > abs(d) && (mn - abs(d)) % (n+1) != 0){
    //     possible = false;
    // }
    // cout << (possible ? "YES\n" : "NO\n");
    bool possible = true;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll y = (2 * a[0] - a[1]) / (n+1);
    ll x = a[0] - y * n;
    for(int i = 0; i < n; i++){
        if(a[i] - x * (i+1) - y * (n - i) != 0) possible = false;
    }
    if(x < 0 || y < 0) possible = false;
    cout << ((possible) ? "YES\n" : "NO\n");
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