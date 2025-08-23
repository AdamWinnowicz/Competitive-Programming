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
    find the min moves to make first element the max and last element the min
*/
 

// Small Observations
/*
    we can just find the first location of a max and the last location of the min
*/
 

// Claims on algo 
/*  
    the answer is the distance of the first loc of max from 1st index plus the distance of the last loc of min from the nth index

    if the indices overlap, subtract one from answer
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    int mx = 0, mn = 101;
    for(int & x : a){
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    int x, y;
    for(int i = 0; i < n; i++){
        if(a[i] == mx){
            x = i;
            break;
        }
    }
    for(int i = n-1; i > -1; i--){
        if(a[i] == mn){
            y = i;
            break;
        }
    }
    int ans = x + (n - 1) - y;
    if(x > y) ans--;
    cout << ans << '\n';
    return 0;
}