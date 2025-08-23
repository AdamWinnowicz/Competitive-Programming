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
    we have some numbers
    
    every multiple of those numbers is good

    count the number of good from 1 to n
*/
 

// Small Observations
/*
    we can just calculate the number of good in the range
*/
 

// Claims on algo 
/*  
    we can use an o(n) loop because the constraints are so small (only 10**5)

    if the constraints were larger, we should use division and the inclusion exclusion principle

    because it is interesting, I will use division
*/
int d;
int cnt(int x){
    return d / x;
}

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, l, m, n; cin >> k >> l >> m >> n >> d;
    int ans = 0;
    ans += cnt(k) + cnt(l) + cnt(m) + cnt(n);
    ans -= (cnt(lcm(k, l)) + cnt(lcm(k, m)) + cnt(lcm(k, n)) + cnt(lcm(l, m)) + cnt(lcm(l, n)) + cnt(lcm(m, n)));
    ans += cnt(lcm(lcm(k, l), m)) + cnt(lcm(lcm(k, m), n)) + cnt(lcm(lcm(n, l), m)) + cnt(lcm(lcm(k, l), n));
    ans -= cnt(lcm(lcm(k, l), lcm(n, m)));
    cout << ans << '\n';
    return 0;
}