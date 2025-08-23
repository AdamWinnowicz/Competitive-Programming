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
    n rooms 

    time at which the light switch is first turned on

    time that each light stays on before turning off for the same duration and repeating the cycle

    return the first moment that the lights are all turned on, or if there is no moment return -1
*/
 

// Small Observations
/*
    We can look at the problem as a bunch of ranges with different start points, and we want to know the first point where all the ranges overlap

    |---------|          |---------|
       |--------|          |---------|
                                        |---------|          |----------|


    |----------|
        |-----------|           
            |----------|

    If the one that starts the latest starts before the first one ends, that is the point that works for all of them

    |----------|           |-----------|
     |-----------|          |-----------|
                 |----------|           |----------|

    Why does this one work?

    The distance between the first and last starting points is greater than k

    On the second iteration, the distance that was originally between them will now be the amount that they overlap

    This means that if all the others start within this overlap that the first point they all meet is the last one in the overlap

    Lets look at it from a slightly different perspective

    The patterns are cyclical, meaning that the only thing that matters are the first two repetitions, as any repetitions afterwards will just mimic the cycle

    Does this mean that we can just simulate the 4 * 10 ** 5 distance? 

    It would be o(n), so probably

    However, how could we check in o(1) if all the segments contain a point?

    if every segment starts less than k before this point, or starts 2*k <= distance <= 3*k

    

    We need to change our approach

    It makes sense to sort the segments by their starting point

    We can go from left to right to see 

    Every segment has a pattern where after the starting point, the next segment is the same but just shifted by 2k

    Therefore all segments can be represented as a[i] + 2kx ---- a[i] + 2kx + k

    We can take the remainder modulo 2k to get the base/initial segment of each of the i segment types

    Now we need to find the smallest integer point s

    such that s is in front of the segment that starts the latest (so that all segments can definitely be included)

    and that s % 2k is within the simplified segments of each chip

    this works because modulo 2k means that one of the previous segments could be shifted by a multiple of 2k and then include s

    How can we find this value of s?

*/
 

// Claims on algo 
/*  
    We can find the shifted starting point of each segment that is originally before the last one such that it is in front of or on the same level as the last one

    We can do this by taking the difference between the last segment starting point and each of the earlier segments and taking the ceiling divided by k, then adding that * k

    We know that the answer must be in the range max(a) to max(a) + k - 1

    This is because if it is not, we cannot guarantee the last segment any other way because it is cyclical

    We can just add the smallest multiple of 2k that gets each a[i] to be greater than or equal to max(a)

    Now we just need to know whether there exists a point s.t all the segments contain it
    
    Greedily the starting point of the new last segment will be the earliest point that will work. 

    When will it not work?

    Only if the minimum of a is now too far away (at least k away)

    How to check this?

    Max(a) - Min(a) >= k --> -1

    else Max(a)

*/

void test_case(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++){
        ll temp = (a[n-1] - a[i]) / k;    
        if(temp % 2 == 1) temp++;
        a[i] += temp * k;
    }
    sort(a.begin(), a.end());
    if(a[n-1] - a[0] >= k){
        cout << "-1\n";
    }
    else{
        cout << a[n-1] << '\n';
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