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
    given an array

    find min number of decreases by one necessary to make all subarrays of length >= 2 have sum of even greater than sum of odd 
*/
 

// Small Observations
/*
    this can be covered by just looking at each subarray of length 2 and then each subarray of length 3

    this is because, if covered by both length 2 and 3, concatenating any subarray on left and right of a subarray of length 3 or 2 can always be made up of subarrays of length 2 and 3 which are already guaranteed to be good

    
*/
 

// Claims on algo 
/*  
    just simulate this check using sliding window
    
    what if we just set every even element equal to the sum of the two odds around it
*/

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll & x : a) cin >> x;
    ll ans = 0;
    for(int i = 1; i < n; i += 2){
        ll around = a[i-1];
        if(i < n - 1) around += a[i+1];
        if(a[i] < around){
            ll diff = around - a[i];
            ans += diff;
            if(i < n - 1){
                a[i+1] = max(0LL, a[i+1] - diff);
            }
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
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}