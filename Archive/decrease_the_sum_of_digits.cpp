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
    we have a number

    how many operations are needed to make the sum of digits smaller than or equal s
*/
 

// Small Observations
/*
    when you increase a digit at a certain location, until that digit becomes 10 you will only increase the total digit sum

    this means that we can skip simulating those operations and just use the current location in the string to determine how many operations would be necessary to make the digit carry over

    each time we do this, we should check whether we got less than s in the total sum and stop if we did

    the string is very short, only 18 characters long, so this should be easy to simulate
*/
 

// Claims on algo 
/*  
    simulate what is described in observations
*/

void test_case(){
    string s; cin >> s;
    s = "00" + s;
    int x; cin >> x;
    int cur = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
        cur += s[i] - '0';
    }
    ll ops = 0;
    for(int i = n - 1; i > -1; i--){
        if(s[i] == '0') continue;
        if(cur <= x) break;
        ll digit_diff = 10 - (s[i] - '0');
        ll loc_diff = n - 1 - i;
        ll ops_per_diff = pow(10, loc_diff);
        ll needed_ops = digit_diff * ops_per_diff;
        int ind = i;
        int removed = s[ind] - '0';
        s[ind] = '9';
        while(ind > 0 && s[ind] == '9'){
            s[ind] = '0';
            if(ind != i) removed += 9;
            ind--;
        }
        s[ind]++;
        ops += needed_ops;
        cur -= removed;
        cur++;
    }
    cout << ops << '\n';
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