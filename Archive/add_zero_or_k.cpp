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
    we have an array of integers

    we can perform k operations

    we can add either 0 or k to each value in each operation

    we want to reach an array where the gcd of the entire array is greater than 1

    
*/
 

// Small Observations
/*
    we can basically add any multiple of k to all values which is <= k * k

    if any value is equal to one, we have to add to it at least once

    if we can make all the values in the array the same, we can definitely make the gcd greater than 1

    mathematically, we start with a1, a2, a3, ... an

    then we add some multiple of k <= k * k to each value

    for example

    a1 + a*k, a2 + b*k, a3 + c*k, ... an + z * k

    then we are able to factor out some value from each of these such that it appears in all of them

    when we add k to the values, we can never change its remainder % k

    however, we can probably try to change its parity

    for example, if k is an odd number, we can add k to every number which is odd to make them even

    then all the numbers would be even, which means gcd is at least 2 

    what if k is even and some numbers are odd?

    going back to the idea with making sure numbers are not 1

    once we have all numbers greater than 1

    e.g 2, 9, 17, 13, 19, 20, 10

    lets say k = 24

    if we have numbers that are <= k, we can add that ai * k to each number to make the number ai * (k + 1) making it divisible by k + 1

    we can do this with all elements which are <= k to make them all divisible by k + 1

    what about the numbers which are greater than k? can we still make them divisible by k + 1?

    ai = k + x (some amount greater than k)

    if we add some multiples of k up to k * k, 

    ai = k + x + y * k

    we get ai = (y + 1) * k + x

    x is a number which is guaranteed to be less than k because it is the remainder modulo k

    this means that we just need to make y + 1 equal to x

    if we can make y + 1 = x, we get ai = x * k + x = x * (k + 1) which is also divisible by k + 1

    y = (remainder mod k) - 1
*/
 

// Claims on algo 
/*  
    add (rem - 1) * k to every value, making it divisible by k + 1

    what if the remainder is 0 (ai is a multiple of k)

    ai = k * z

    ai = k * z + y * k

    ai = k * (z + y)

    if we want ai to be divisible by k + 1, z + y = k + 1
    
    y = k + 1 - z

    one more try

    let's consider each value ai = b*k + r

    how can we make all ai divisible by something by adding y * k

    ai = b * k + r + y * k

    we can set y equal to any value from 0 to k

    we cannot always make values divisible by k because we cannot make the remainder 0 by adding multiples of k

    is it possible to make b a multiple of r?

    yes

    ai = z * r * k + r

    ai = r * (z * k + 1)

    let's look at this differently

    a[i] + b[i] * k must be congruent to 0 modulo d (d > 1) if the gcd > 1 for all final values

    this means that a[i] is congruent to  - b[i] * k modulo d

    so the remainder of a[i] modulo d must be equal to the opposite remainder of b[i] * k 

    I'm really stuck

    what can each number be represented as

    a[i] = b * k + r

    can we make the gcd into a specific value?

    we can make each number divisible by k + 1

    this is because every time we add k to a value, we decrease its remainder modulo k + 1

    also, the remainder modulo k + 1 is always <= k, so we can do this in the right number of operations
*/

void test_case(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        ll rem = a[i] % (k + 1);
        cout << a[i] + rem * k << (i == n - 1 ? "\n" : " ");
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