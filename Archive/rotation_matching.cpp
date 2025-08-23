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
    two perms a and b

    we can shift cyclically either of them

    we want to maximize the number of equal characters

    output the maximum
*/
 

// Small Observations
/*
    what is a cyclic shift?

    all elements get moved to the right or left, and the element on the edge wraps around

    can shifting the elements of a be sufficient to cover every case?

    it seems that shifting elements of b has the same affect as shifting the elements of a in the opposite direction, lets see if it works

    13425 --> 34251
    51243     51243
    if we do the opposite
    13425     13425  
    51243 --> 35124
    all elements are still paired the same

   

*/
 

// Claims on algo 
/*  
    are we able to simulate this in o(n)?

    n is only 2 * 10 **5, so o(n) is good

    shifting just means pairing with the element that is currently to the right by x, where x is the shift to the right

    we can increment this value x

    when an index + x >= n, we can just take that modulo n to see what it would wrap around to 

    actually, this is o(n**2) so we need a faster way

    because they are permutations, lets just find the two locations of every value from 1 to n and add one to the shift by their difference

    answer is the maximum of all the shifts
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    map<int,int> loc_a, loc_b;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        loc_a[a] = i;
    }
    for(int i = 0; i < n; i++){
        int b; cin >> b;
        loc_b[b] = i;
    }
    vector<int> shift(n);
    for(int x = 1; x <= n; x++){
        int diff = loc_b[x] - loc_a[x];
        if(diff < 0){
            diff += n;
        }
        shift[diff]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, shift[i]);
    }
    cout << ans << '\n';

    return 0;
}