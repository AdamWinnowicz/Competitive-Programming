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
    given a number of tiles n

    paint the tiles in the maximum number of colors

    such that for every factor of n

    each multiple of the factor has the same color tile each time
*/
 

// Small Observations
/*
    lets look at a small example n = 4

    2 is a factor of n

    1 2 1 2 is valid 

    you can never have a distance of n, so we don't need to worry about the outsides being the same

    this is definitely cyclical within the largest factor of n

    it also is cyclical with the smallest factor of n

    if it is prime, all colors can be different

    if it is not prime, all colors can be different within the cycle of its smallest factor greater than 1

    we can check if a number is prime in sqrt(n) which works here

    let's take 8 for example

    because 2 is a factor, we need all cycles of size 2 to be the same

    1 2 1 2 1 2 1 2

    any other factor of 8, e.g 4

    should already be met

    what about a more complex one like 24

    smallest factor is still 2, but does the 2 pattern work or do they all have to be the same

    1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2

    24 is divisible by 3, so every three has to be the same as well

    this means that it does not work now because a cycle of 2 conflicts with a cycle of 3

    so all of them have to be the same, my idea with smallest cycle does not work

    let's look at the factors of a number

    let's try 20 = 2 * 2 * 5

    what truly matters is definitely the prime factorization, because any non prime factors are covered by one of their factors

    so what is the prime factorization of 24 from before?

    2 ** 3 * 3

    this means that every 2 has to be the same and every 3 has to be the same, which makes all of them the same

    Going back to my idea of the largest cycle, we just need to simulate a cycle of the largest prime factor, which is guaranteed to be less than sqrt so it is good

    one thing that is interesting is that if you go forward by one factor and then back by the other, you essentially go forward by their difference

    that's why 3 and 2 make a cycle of size 1, because you can move forward each time by 1

    lets look at the number 10 = 5 * 2

    5 - 2 = 3, so we can go forward 3

    then 3 - 2 = 1, so we can go forward 1

    1 2 1 2 1 2 1 2 1 2 1

    we have to use all 1 again

    what about a number like 39 = 3 * 13

    it still goes forward by one because 13 % 3 = 1

    what about 17 * 3 = 51

    17 % 3 = 2

    but then if we add another 17

    19 % 3 = 1

    this seems to actually be a problem about linear combination 

    p1 * x + p2 * y = 1

    is it always possible with any values of p1 and p2?

    YES!

    linear combination of two numbers is always a multiple of their gcd

    since both numbers are different and prime, the gcd = 1

    this means that the linear combination is any multiple of 1, which includes 1

    
*/
 

// Claims on algo 
/*  
    if there are two or more prime factors of n, the answer is always only 1 color

    otherwise, the answer is the smallest factor other than 1
*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    unordered_set<ll> prime_factors;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0) prime_factors.insert(i);
        while(n % i == 0) n /= i;
    }
    if(n != 1) prime_factors.insert(n);
    if(prime_factors.size() == 1){
        cout << *prime_factors.begin() << '\n';
    }
    else{
        cout << 1 << '\n';
    }

    return 0;
}