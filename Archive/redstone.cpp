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
    gears with ai teeth

    leftmost gear goes at 1 rev / sec

    each gear has a speed of ai / a(i-1) * speed of i-1th gear

    we want the rightmost gear to have 1 rev / sec as well
*/
 

// Small Observations
/*
    we can probably represent this mathematically

    what is the speed of the final gear

    it is the speed of left gear times the ratio

    which is the speed of other left gear times the ratio

    which is the speed of prev times the ratio

    continuing

    so for some sequence maybe like this

    6 3 6 9

    final speed = (1 * (3 / 6)) * (6 / 3) * (9 / 6)

    (3 * 6 * 9) / (3 * 6 * 6)

    6 6 3 9

    (6 / 6) * (3 / 6) * (9 / 3)

    1 * 1/2 * 3

    = 3 / 2

    6 3 9 6

    6 / 3 * 3 / 9 * 9 / 6

    6 * 3 * 9 / 3 * 9 * 6 = possible

    6 3 6 9

    6 / 3 * 3 / 6 * 6 / 9

    6 * 3 * 6 / 3 * 6 * 9

    we need to rearrange it such that each number appears in both the 

    6 5 8 6

    
*/
 

// Claims on algo 
/*  
    just find 2 of the same number and its good
*/

bool test_case(){
    int n; cin >> n;
    map<int,int> cnt;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    for(const auto & p : cnt){
        if(p.second >= 2){
            return true;
        }
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}