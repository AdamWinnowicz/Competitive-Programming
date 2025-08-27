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
    sequence of all numbers that don't contain the digit 4

    find the kth value in the sequence where k is up to 10**12
*/
 

// Small Observations
/*
    if the sequence had every value, the kth value would be k

    because there are some values that are missing, we skip them, meaning we can go higher

    if we choose a value of m for the kth value, that means that there must be m - k values with a 4 in the range from 1 to m

    there is a 4 every 10 elements guaranteed

    there is also a string of 10 4s in a row every 100 elements

    then there is a string of 100 4s in a row every 1000 elements etc.

    when we get to a value 3 at the end, we know we skip the next one and go straight to 5

    when we get 399...99 somewhere, we know we skip everything in between and go straight to 500...00

    1 2 3 5 6 7 8 9 10 11 12 13 15 16 17 18 19 20 21 22 23 25 

    at the start, we increase the value every 9 elements from what it should be 

    first, use four elements to get to 5

    then use 9 elements to get to 15

    then use 9 elements to get to 25

    then use 9 elements to get to 35

    then use 5 elements to get to 50

    then use 4 elements to get to 55

    then use 9 elements to get to 65

    then use 9 elements to get to 75
    
    then use 9 elements to get to 85

    then use 9 elements to get to 95

    then use 9 elements to get to 105

    then use 9 elements to get to 115

    then use 9 elements to get to 125

    then use 9 elements to get to 135

    then use 5 elements to get to 150

    then use 4 elements to get to 155

    the jumps where 4 is in the 10s place jumps by 20 for a cost of 9

    what if you are at 395

    use 5 elements to get to 500

    then use 4 elements to get to 505

    this time we jumped by 110 because the 4 is in the 100s place

    110 = 101 + 9 

    can we think of this differently?

    There are 9 options to choose for each digit

    this means that there are 9 1 digit numbers

    there are 81 2 digit numbers

    there are 9**3 3 digit numbers

    etc.

    we also know that the first of each digit number will always exist and will be the (9**digit)th number

    So we should find the length of the number that we need to find

    Then we can check the power of 9 of each digit and multiply it by the largest digit which keeps the position of the number below k

    we can keep doing this until we construct the whole number

    let x = 9 ** digit

    the xth value is 1 * 10 ** digit

    for example, the 9th value is 10, the 81st value is 100, the 729th value is 1000

    then we can multiply by a digit 

    for example, the 18th value is 20, the 27th value is 30, the 36th value is 50, the 45th value is 60

    if the digit we want to multiply by is greater than 4, the factor we multiply by is (digit - 1), otherwise it is just digit
*/
 

// Claims on algo 
/*  
    
*/

void test_case(){
    ll k; cin >> k;
    vector<ll> ans(13);
    for(ll p = 12; p > -1; p--){
        //debug(k);
        ll val = pow(9LL, p);
        if(val > k) continue;
        ll new_val = val;
        ll highest_d = 1;
        for(ll d = 2; d < 10; d++){
            if(d == 4) continue;
            ll cost_factor = (d > 4 ? d - 1 : d);
            //debug(val, cost_factor);
            if(val * cost_factor > k) break;
            else{
                new_val = val * cost_factor;
                highest_d = d;
            }
        }
        ans[p] = highest_d;
        k -= new_val;
    }
    //debug(ans);
    ll ind = 12;
    while(ans[ind] == 0){
        ind--;
    }
    string answer;
    for(int i = ind; i > -1; i--){
        answer += to_string(ans[i]);
    }
    cout << answer << '\n';
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