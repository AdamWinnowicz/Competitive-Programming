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
    given n sequences of numbers

    for each value x from 1 to m, define f(x) to be the maximum number of x after setting it to be the mex of a sequence and the value x

    we can choose a sequence as much as we want
*/
 

// Small Observations
/*
    this probably has something to do with dp

    when is f(x) greater than x

    you can always set f(x) = x by doing no operations, so that is the lower bound

    therefore, any sequences with a mex of less than x should never be chosen because it would lower the mex

    however, if we have a sequence where the mex is x or x + 1, when we add x to the sequence the mex becomes x + 1

    this means that we can change x to be x + 1

    this can form a sort of staircase - actually, not even necessary

    if we have mexes of x, x + 1, x + 2, x + 3, x + 4

    if any number currently has a mex of greater than or equal to x, look for the largest one

    this is because adding x to that set does not change the mex, but actually makes x equal to that mex

    then on the next operation we can use the same big guy and get mex + 1

    so in the example above we can first get x = x + 4

    then we can use it in the sequence to get x = x + 5

    and then we are done because adding x to any sequence will lower its value

    so my idea is

    can we just find the sequence with the largest mex and make x = mex + 2 until x is greater than the largest mex?

    well, we can definitely say that if x is greater than the largest mex, always just keep it at x

    otherwise, there might be a big problem in my logic

    0 1 3 4 5 6 7 9 14

    if we have any value of x, we can change it to 2

    then we can add that to the sequence and the new mex is 8, so we change it to 8

    then we can't get more from it because there is a hole in the sequence

    this means that the best value we can get from each sequence is the second place that a value is not there in the perm

    if we know this, we can just find the maximum of all these values and that should always be our answer, right?

    why does it matter for all the values of 1 to m if it doesn't change though?

    the value of j from 1 to m could be larger than the best we can get, so I guess we just take the max
*/
 

// Claims on algo 
/*  
    let's try the above and see if it fails


*/

void test_case(){
    ll n, m; cin >> n >> m;
    vector<ll> second_missing(n);
    ll overall_best = 0;
    for(int i = 0; i < n; i++){
        ll l; cin >> l;
        set<ll> vals;
        for(int j = 0; j < l; j++){
            ll x; cin >> x;
            vals.insert(x);
        }
        ll best = -1;
        ll needed = 2;
        for(ll j = 0; j <= l + 2; j++){
            if(vals.find(j) == vals.end()){
                needed--;
                if(needed == 0){
                    best = j;
                    break;
                }
            }
        }
        // if(needed == 1){
        //     best = *vals.end() + 1;
        // }
        // else if(needed == 2){
        //     best = *vals.end() + 2;
        // }
        overall_best = max(overall_best, best);
    }
    ll num_less = min(m + 1, overall_best + 1);
    ll num_more = (m + 1) - num_less;
    // arithmetic sequence 
    // there should be num_more elements: overall_best + 1, overall_best + 2, overall_best + 3, ... m - 1, m
    // each time you get m + overall_best + 1 for every 2 elements in the sequence of length num_more
    ll value_more = (m + overall_best + 1) * num_more / 2;
    ll value_less = num_less * overall_best;
    //debug(overall_best, value_more, value_less, num_more, num_less);
    ll ans = value_more + value_less;
    cout << ans << '\n';
    
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