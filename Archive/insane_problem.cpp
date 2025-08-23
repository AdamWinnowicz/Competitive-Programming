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
    given a number k

    for any k**n, determine if there is a ratio of y to x such that it is k**n

    where y is in some range and x is in some range less than 10**9
*/
 

// Small Observations
/*
    if ranges are only up to 10**9, y/x can be at most 10**9

    this means that we can easily loop over all powers of k (k ** n) in o(logk(10**9)) time, which is very small < 30

    for each of these, we need to determine what values of y and x have that ratio

    y / x = z

    wait

    if z is always k ** n, that means that the only factors not shared by y and x must be some z **n

    this is very interesting

    we could probably change the problem to be like

    if we have x = 2 (lets say)

    we can make y any number that is 2 * k ** n

    because when we divide them it will be k ** n which is good

    for any value of x, we can keep multiplying it by k and then check how many times it lies in the range of y

    we could double count though

    lets say that k = 2 and a valid x is 4, 8, 16

    when we count that 4 * k ** 2 can be 16 we don't want to also count it another time when we just start with x = 8 and 8 * k ** 1 = 

    nevermind, this is not double counting because it is with a different value of x

    this would be way too difficult to count because we can't loop over 10**9 values of x

    let's approach it differently, using what we knew from the start

    we can loop over all powers of k

    this power of k can be called z

    we have that y / x = z

    so y = z * x

    and x = y / z

    so there are some x, y pairs where y is z times larger than x

    this is possible for every x in the range as long as z * x is in the range of l2, r2

    z * x <= r2

    x <= r2 / z

    x must also be at least l1

    x >= l1

    and z * x >= l2

    x >= l2 / z

    so just count how many x are from max(l1, l2 / z) to min(r1, r2 / z)

    and add that to the answer

*/
 

// Claims on algo 
/*  
    complete the process of calculating for every possible value of z

    add to answer each time
*/

void test_case(){
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    ll z = 1;
    while(z <= 1e12){
        ll L = max(l1, (l2 + z - 1) / z);
        ll R = min(r1, r2 / z);
        ll possible = R - L + 1;
        if(possible > 0)
            ans += possible;
        z *= k;
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