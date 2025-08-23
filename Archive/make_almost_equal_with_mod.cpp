#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 2){
        cout << max(a[0], a[1]) << '\n'; return;
    }
    for(int b = 0; b <= 60; b++){
        bool on = false, off = false;
        for(ll val : a){
            if(val & (1LL << b)) on = true;
            else off = true;
        }
        if(on && off){
            cout << (1LL << b+1) << '\n'; return;
        }
    }
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