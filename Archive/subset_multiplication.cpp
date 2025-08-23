#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n; cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    ll x = 1;
    for(int i = 0; i < n-1; i++){
        ll g = __gcd(b[i], b[i+1]);
        if(g != b[i]){
            ll factor = b[i] / g;
            x = (factor * x) / __gcd(factor, x);
        }
    }
    cout << x << '\n';
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