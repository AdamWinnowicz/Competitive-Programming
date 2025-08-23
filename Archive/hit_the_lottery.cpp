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
    we have bills 1, 5, 10, 20, 100

    we have a number n

    make the number n with the smallest possible number of bills
*/
 

// Small Observations
/*
    each bill is a multiple of each of the smaller bills

    therefore, greedy algorithm of choosing the largest bill should work

    this is because every larger bill is always better at covering its value than any set of smaller bills

    this is different than the regular coin change problem

    because each coin can be made up by smaller coins, choosing smaller coins instead would still need to make up the same value but with greater bills (not optimal)
*/
 

// Claims on algo 
/*  
    always choose the largest coin as much as we can
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> coins = {100, 20, 10, 5, 1};
    int n; cin >> n;
    int ans = 0;
    for(int c : coins){
        ans += n / c;
        n %= c;
    }
    cout << ans << '\n';

    return 0;
}