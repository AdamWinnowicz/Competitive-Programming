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
    given range from l to r inclusive

    what are a, b, c in the range that maximizes (a ^ b) + (a ^ c) + (b ^ c)?
*/
 

// Small Observations
/*
    constraints are way too high to loop over all values, so we need an o(1) way to check (conditional)

    when doing bitwise problems, you can normally treat each bit independently

    what do we know about an arbitrarily bit from the trio?

    if a, b, and c all have the bit set, we don't gain anything from the bit

    likewise if they all don't have the bit set

    if a and b have it set, we get 2 * b because it only fails with a ^ b

    same with any other 2 elements b, c ... a, c

    if only one has the bit set, it will also add 2 * b because it appears twice

    basically, if all have them set or none have them set, we get nothing

    otherwise we get 2 * b

    Therefore, we want the three numbers to have a bit set either once or twice, never three or zero times

    Maybe we could get close to the solution with only two elements, because the two numbers we choose could be bitwise opposite

    1000 0111 2**x and 2**x - 1

    10101010
    01010101

    what if we just choose a random element in the range and then try to make the other ones complement it (together)

    maybe instead of a random element we should choose r, because we can try to just fill all the places that it has 0

    1001011100100100010011110

    0110100011011011101100001 (what we want)

    if there is a number without the first bit set in the range, start building it by choosing that

    otherwise we are forced to use that bit but we can just ignore it bc it is impossible anyways

    keep doing this for every bit

    eventually we will have a number in the range necessary that complements the value as well as possible

    this might be all we need, because the only time that we cannot do what we want it will be impossible to get that anyways

    so we can just choose arbitrarily for the third element

    let's test on a weird case

    9 = 1001
    10 = 1010
    11 = 1011
    12 = 1100
    13 = 1101
    14 = 1110
    15 = 1111

    start with r = 1111

    try the most sig bit to be off - impossible, we must have it on

    try the next most to be off - possible

    try the next most to be off - possible

    try the next most to be off - impossible

    1001

    1111
    1001

    however, this is actually not all that we need, so this algo might not work

    now we know that we need the 1-1 groups to have a 0

    maybe we can start with the largest element and try to set the bits to be what we want

    what if we consider the case for a power of 2

    10000
    01111

    this will allow all bits here to be good

    in the range from l to r, there may be a power of 2 or may not

    however, if there is not a power of 2, we cannot change the bits that are the same in both l and r, like in example from 9 - 15

    however, once there is a place that the bits differ in, we know that it switched from off to on

    this means that there was a smaller power of 2 which was reached at some point

    in the example, it is from 11 to 12 where the smaller power of 2 is 1011 to 1100 or 011 to 100 because the same bits don't matter

    the key observation is that because these larger bits cannot be changed, we can always reduce the problem to one where the most significant bit does change, which guarantees a power of 2 in the range
*/
 

// Claims on algo 
/*  
    ignore the bits that are the same

    find the first place they differ

    take that power of 2 and one less than it

    take one random element that is not equal to either
*/

void test_case(){
    int l, r; cin >> l >> r;    
    int x = 0;
    for(int b = 29; b > -1; b--){
        int p = (1 << b);
        bool first = p & l, second = p & r;
        if(first || second) x += p;
        if(first != second){
            break;
        }
    }
    int y = x - 1;
    int z;
    for(int i = l; i <= r; i++){
        if(i != y && i != x){
            z = i;
            break;
        }
    }
    cout << x << " " << y << " " << z << '\n';
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