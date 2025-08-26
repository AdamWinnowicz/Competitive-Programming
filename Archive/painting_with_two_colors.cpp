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
    given a row of n cells, all painted white

    paint a subsegment of a cells red

    then paint a subsegment of b cells blue

    we can paint over red cells with blue cells

    determine whether you can make a symmetric coloring
*/
 

// Small Observations
/*
    if the subsegment of b cells that you paint is larger than the subsegment of a cells (b > a) we can paint over the subsegment of a cells meaning that only b needs to be good

    however, this is not the same for a because we cannot paint over the a

    therefore, it is not possible when b is of different parity than n

    it is also not possible when a is of different parity of n and larger than b
*/
 

// Claims on algo 
/*  
    
*/

bool test_case(){
    int n, a, b; cin >> n >> a >> b;
    if((b % 2) != (n % 2)) return false;
    if(a > b && ((a % 2) != (n % 2))) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "YES\n" : "NO\n");
    }

    return 0;
}