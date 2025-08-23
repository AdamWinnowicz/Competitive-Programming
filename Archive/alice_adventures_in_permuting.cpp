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
    linear array where b is the slope and c is the starting point

    How many times do we have to set the max equal to the mex until all elements from 0 to n-1 are included?
*/
 

// Small Observations
/*
    When is it impossible? 

    When all the elements are zero, the max will fluctuate infinitely from 1 to 2 unless the length is only 2

    The reason this happens is that the mex becomes the max

    This could happen with an array like 0 1 2 2 2 2 2 because 2 would become three then four then three again 

    However, this type of array can only happen when elements are the same (duplicates) because otherwise the mex cannot become the mex

    2 2 2 2 2 2 2 2
    first we get 0 2 2 2 2 2 2 2
    then 0 1 2 2 2 2 2 2 2 
    then 0 1 3 2 2 2 2 2 2 
    then 0 1 4 2 2 2 2 2 2
    then 0 1 3 2 2 2 2 2 2
    ...
    forever

    what if we have less elements

    2 2
    0 2
    0 1
    good

    2 2 2
    0 2 2
    0 1 2
    good

    2 2 2 2
    0 2 2 2
    0 1 2 2
    0 1 3 2
    good

    2 2 2 2 2
    0 2 2 2 2
    0 1 2 2 2
    0 1 2 3 2
    0 1 2 4 2
    0 1 2 3 2
    ...

    3 3 3 3
    0 3 3 3
    0 1 3 3
    0 1 2 3
    good

    3 3 3 3 3
    0 3 3 3 3
    0 1 3 3 3
    0 1 2 3 3
    0 1 2 3 4
    good

    if n > c + 2 and b = 0 (allowing duplicates) it will definitely not be possible

    what happens if we dont have duplicates? will it always be possible?

    1 2 3 4 5
    1 2 3 4 0

    0 2 4 6 8
    0 2 4 6 1
    0 2 4 3 1
    takes two operations because we already have 2 of the elements we need

    0 5 10 15
    0 5 10 1
    0 5 2 1
    0 3 2 1
    takes three operations because we already have 1 element we need

    what if we raise the starting point?

    1 3 5 7 9
    1 3 5 7 0
    1 3 5 2 0
    1 3 4 2 0
    takes 3 operations because we already have 2 of elements we need

    looks like not much changes

    To prove this, I guess we could say that we always need x number of operations where x is the number of elements we dont have --- as a lower bound

    It would be impossible to get this in less operations, because you can only get one element per operation

    How do we know that we will never need more operations?

    If we choose the max every time and all elements are distinct, we will always be able to choose the unique max element and make it into the mex

    Because all elements smaller than n are good, if we always choose the largest elements we will get all of them to be the necessary smaller elements and we will be done 
*/
 

// Claims on algo 
/*  
    If b = 0 && n > c + 2 ---> -1

    Otherwise:

    We need to find the number of elements less than n that we already have

    We can do this by just checking n - c (the starting point) and then doing integer division by the slope (b)

    This should give us the answer!
*/

void test_case(){
    ll n, b, c; cin >> n >> b >> c;

    if(b == 0 && n > c + 2){
        cout << "-1\n";
    }
    else{
        ll already_have;
        if(c >= n) already_have = 0;
        else if(c == n - 1 || b == 0) already_have = 1;
        else{
            already_have = ((n - 1) - c) / b + 1;
        }
        cout << n - already_have << '\n';
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