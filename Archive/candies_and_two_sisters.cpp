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
    n = a + b

    a > b

    how many ways are there to have this
*/
 

// Small Observations
/*
    if n is even e.g 8

    a can be 5 6 7

    if n is odd e.g 9

    a can be 5 6 7 8

    n = 10

    6 7 8 9
*/
 

// Claims on algo 
/*  
    if n 
*/

void test_case(){
    int n; cin >> n;
    if(n % 2 == 0){
        cout << n / 2 - 1 << '\n';
    }
    else cout << n / 2 << '\n';
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