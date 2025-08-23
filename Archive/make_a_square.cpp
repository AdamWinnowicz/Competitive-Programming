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
    given an integer

    determine the minimum number of deletions of digits to make it a perfect square

    the positive integer we create must be without leading zeros
*/
 

// Small Observations
/*  
    the number is in the range 2 * 10 **9

    this means that sqrt(n) is an ok time complexity

    therefore, we could check every perfect square in the range and see how many moves are necessary for each

*/
 

// Claims on algo 
/*  
    because the length is only up to 9, we would have to do at worst 9 operations, which can be calculated in 9 operations

    therefore time complexity would be O(sqrt(n) * 9) which is ok

    how can we count the number of necessary moves? 

    how can we tell that it is impossible to have a number?

    even better idea:

    because there are only 2**9 possible subsets of the string of length 9, we can check all possible subsets

    for each subset, check that it does not have leading zeros

    then check if it is a perfect square by checking against precomputed perfect squares
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_set<string> perfect_squares;
    for(int i = 1; i <= sqrt(n); i++){
        perfect_squares.insert(to_string(i * i));
    }
    string num = to_string(n);
    int len = num.length();
    int ans = 10;
    bool found = false;
    for(int mask = 1; mask < (1 << len); mask++){
        string x;
        for(int b = 0; b < len; b++){
            if((1 << b) & mask){
                x += num[b];
            }
        }
        if(x[0] == '0') continue;
        if(perfect_squares.find(x) == perfect_squares.end()) continue;
        int ops = len - x.length();
        ans = min(ans, ops);
        found = true;
    }
    if(!found){
        cout << "-1\n";
    }
    else cout << ans << '\n';
    return 0;
}