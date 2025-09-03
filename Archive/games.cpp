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
    given a list of colors of home and guest uniform

    count the number of times that the home uniform is equal to the guest uniform of the n - 1 other teams
*/
 

// Small Observations
/*
    
*/
 

// Claims on algo 
/*  
    
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<int,int> cnt_guest;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int away; cin >> a[i] >> away;
        cnt_guest[away]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += cnt_guest[a[i]];
    }
    cout << ans << '\n';

    return 0;
}