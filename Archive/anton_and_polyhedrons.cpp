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
    we have a list of n polyhedrons

    determine the number of sides
*/
 

// Small Observations
/*
    
*/
 

// Claims on algo 
/*  
    count the number of sides as we go through
*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "Tetrahedron") cnt+=4;
        else if(s == "Cube") cnt += 6;
        else if(s == "Octahedron") cnt += 8;
        else if(s == "Dodecahedron") cnt += 12;
        else cnt += 20;
    }
    cout << cnt << '\n';

    return 0;
}