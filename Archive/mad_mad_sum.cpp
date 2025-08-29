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
    given an array

    calculate the sum of all arrays created in the process of setting each element in the array equal to the max duplicate of the prefix ending at i
*/
 

// Small Observations
/*
    the first element will have a max duplicate of 0

    the second element will have either a max duplicate of 0 or a max duplicate of the element that appears both times'

    the values of bi are non decreasing, as the max duplicate of a prefix also appears in all prefixes after, so the max duplicate of those prefixes is at least the current one

    each time, the array sets at least one value to 0 which is the first one

    so we will have at most n operations

    by setting an element equal to the max duplicate

    if we just want to tell what the next array will be like, how can we do so quickly?

    we can look for the max element that appears twice, call it m

    any element that doesn't appear twice cannot appear in the next array

    at and after the second occurence of m, the max duplicate is m, no matter what

    then we also know that we will get this pattern

    ............ m m m m m m m m m m
    ............ . m m m m m m m m m 
    ............ . . m m m m m m m m 
    etc.
    ............ . . . . . . . . . m

    this means that this part of the sum will be m * l * (l + 1) / 2

    now we can consider the next largest element that appears twice

    keep going until we find one with a second index that is less, call it s

    then we fill the other ones 

    ........ s s s m m m m m m m m m m
*/
 

// Claims on algo 
/*  
    make the first array b in this way

    then we can use the l * (l + 1) / 2 trick to calculate it over all operations

    first idea wrong

    new idea

    ex.

    1 1 2 2 

    0 1 1 2
    0 0 1 1
    0 0 0 1

    1 1 2 2 2 2

    0 1 1 2 2 2
    0 0 1 1 2 2
    0 0 0 1 1 2

    key observation

    everything shifts to the right after the first move

    this means that the total sum is the original array + the second array + second array - suff[n - 1] + second array - suff[n - 2] + ...
*/

void test_case(){
    ll n; cin >> n;
    vector<ll> second_occ(n + 1, -1);
    unordered_set<ll> seen;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ans += x;
        if(seen.count(x) && second_occ[x] == -1){
            second_occ[x] = i;
        }
        seen.insert(x);
    }
    vector<ll> b(n);
    for(ll val = n; val > 0; val--){
        ll curr_loc = second_occ[val];
        while(curr_loc != -1 && curr_loc != n && b[curr_loc] == 0){
            b[curr_loc] = val;
            ans += val;
            curr_loc++;
        }
    }
    for(int i = 1; i < n - 1; i++){
        if(b[i] != b[i-1] && b[i] != b[i+1]){
            b[i] = b[i-1];
        }
    }
    for(int i = n - 1; i > 0; i--){
        b[i] = b[i-1];
    }
    for(ll i = 0; i < n; i++){
        ans += b[i] * (n - i);
    }
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