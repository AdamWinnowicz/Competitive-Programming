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
    construct array of length n with exactly k positive subarrays
*/
 

// Small Observations
/*
    n is very small, only up to thirty

    for our positive elements we can use 1, for negative we can use -1000 to separate segments

    the idea I have is

    greedily try to make the longest segement that is positive by just doing 1 1 1 1 1 1 1 1 until adding another one will make there be greater than k subarrays
    
    then use a -1000 to separate the groups, then continue with this process until we hit exactly k

    this seems right, but can we always guarantee k within the range 0 to n * (n + 1) / 2?

    lets choose n = 5

    the max would be 5 * (5 + 1) / 2 = 5 * 3 = 15

    so can we make 14?

    1 1 1 1 -1000

    in this case is does not directly work because we need some subarrays from the past ones to be included, 4 to be exact

    so we need to choose a number that keeps them positive for 4 but not on the last one

    1 1 1 1 -1

    this one doesn't completely work because one sum is 0

    so lets use 2 instead

    2 2 2 2 -1

    still positive for everything, just not for all of the last ones

    this should now work greedily for everything, we just need to choose the final element correctly

    lets say we want to make 6

    2 2 2 -1000 -1000

    once we reach the desired amount, just put -1000 for everything else

    actually, we can probably just do

    2 2 2 2 2 2 2 2 2 ... until we get greater than k and then choose the final element to make the exact amount we need and then use -1000 for all the rest

    sounds like a plan
*/
 

// Claims on algo 
/*  
    implement the idea above
*/

void test_case(){
    int n, k; cin >> n >> k;
    int will_make = 1;
    vector<int> ans;
    while(k - will_make >= 0) {
        k -= will_make;
        will_make++;
        ans.push_back(2);
    }
    if(k != 0){
        int values_we_have = will_make - 1;
        int to_make_all_negative = -1 * values_we_have * 2 - 1;
        int to_save_k_subarrays = to_make_all_negative + 2 * k;
        ans.push_back(to_save_k_subarrays);
    }
    while(ans.size() < n){
        ans.push_back(-1000);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n - 1 ? "\n" : " ");
    }
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