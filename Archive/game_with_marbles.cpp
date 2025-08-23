#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

// Problem Statement
/*
    
*/
 

// Small Observations
/*
    
*/
 

// Claims on algo 
/*  
    sort by a + b
*/

void test_case(){
    int n; cin >> n;
    vector<pair<ll,ll>> c(n);
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        c[i] = {a, 0};
    }
    for(int i = 0; i < n; i++){
        ll b; cin >> b;
        c[i] = {c[i].first, b};
    }
    sort(c.begin(), c.end(), [](pair<ll,ll> x, pair<ll,ll> y){
        return (x.first + x.second) > (y.first + y.second);
    });
    ll A = 0, B = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            A += c[i].first - 1;
        }
        else{
            B += c[i].second - 1;
        }
    }
    cout << A - B << '\n';
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