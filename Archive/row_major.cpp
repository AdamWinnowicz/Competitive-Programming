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
    find the minimum number of distinct characters in a string of length n
    
    this string cannot be a row major order of a bad grid - what does that mean?

    

    
*/
 

// Small Observations
/*
    there cannot be adjacent characters that are the same - this means that non adjacent characters can be the same

    we want to minimize the number of unique characters, so lets try to use the same characters as many times as possible without creating a bad string

    what ordering works nicely?

    ababababab
    bababababa
    ababababab
    ...

    this might not always work, because it can be any grid (doesn't have to be n x n)

    string is length r x c always, so there are some fixed grids that work

    a
    b
    a
    b
    a
    b
    a
    b

    so no adjacent characters in the row major order can be the same, making the ordering above incorrect

    a b
    c a
    a b 
    c a

    any factor k of the number n is a possible row length

    if k = 3

    a b c
    b c a
    c a b
    ...

    characters 1 and 4, 2 and 5, 3 and 6, 4 and 7, 5 and 8, 6 and 9 etc must be different

    can we just look at the largest factor and make a cycle of that length to avoid any adjacencies?

    example: n = 10, factors: 1, 2, 5, 10

    try to use the least characters to satisfy each factor
    
    k = 1 (and mirror 10) a b a b a b a b a b 
    
    k = 2

    a b a b a
    b a b a b

    k = 5

    a b
    a b
    a b
    a b
    a b
    
    fails, lets change it minimally

    a b
    c a
    b c
    a b
    c a
    cycle of length k + 1 works

    is it possible to achieve with a smaller cycle?

    cycle is always at least length 2, and we saw that length 2 does not work

    maybe we just need to choose the smallest cycle that isnt a factor

    n = 12
    factors: 1, 2, 3, 4, 6, 12

    we must have cycle of at least length 5, but is it sufficient?

    a b c d
    e a b c
    d e a b

    a b c d e a
    b c d e a b

    works for 6 as well


*/
 

// Claims on algo 
/*  
    as long as the length of the cycle is not equal to one of the factors that could be the length of the row, it will ofset the row and be able to nicely avoid conflicts

    find all factors of n

    loop through factors and find the first place where there is a gap f[i] > f[i-1] + 1

    our cycle should be length f[i-1] + 1 greedily
*/

void test_case(){
    int n; cin >> n;

    set<int> x;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            x.insert(i);
            x.insert(n / i);
        }
    }
    vector<int> f;
    for(int val : x) f.push_back(val);
    int cycle;
    for(int i = 1; i < f.size(); i++){
        if(f[i] > f[i-1] + 1){
            cycle = f[i-1] + 1;
            break;
        }
    }
    string ans;
    char c = 'a';
    for(int i = 0; i < n; i++){
        if(i % cycle == 0){
            c = 'a';
        }
        ans += c;
        c++;
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