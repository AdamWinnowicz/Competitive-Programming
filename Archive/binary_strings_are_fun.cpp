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
    given a binary string

    for each prefix, find the number of good extensions and return the sum


*/
 

// Small Observations
/*
    extension is always odd because it always becomes length 2k - 1

    we need to check whether an extension is good or not

    what really is an extension? 

    insert an element in every even index

    after insertions, is each character of the original string the most common in its prefix?

    the first element will always be the most common in its prefix

    the second element depends on the first - if the first is the same, we can have either a zero or a one inserted before it

    if the previous one is guaranteed to be a median, that means at least 2 out of 3 are good

    therefore we can just keep guaranteeing the median for every other one, giving us two possibilites for each one

    
*/
 

// Claims on algo 
/*  
    How can we count the possibilities as we go left to right?

    Something to do with combinatorics, multiplying the number of possibilities for each location of the insertion

    we need to find the first location where we can have the median no matter what we choose

    just add elements as we go from left to right and consider the prefix each time

    we always know that there will be some fixed elements based on the previous 

    as we go from left to right, we can keep track of the number of fixed positions that can have either a zero or one

    this should work because those positions are dependent on a previous prefix

    at each new element, we know that the previous ones will be a median with the number of fixed positions that we have

    however, this new element might need some of the non-fixed positions to have a specific property

    the new element has to be the median, so we need to keep track of the counts of ones and zeros to see how far off we are with only the fixed positions

    then there are n choose k ways to select the k elements that we need to be the same as the current element to make it the median

    for each of the open positions left after that, there are two possibilities so 2**c where c is the number of open positions

    therefore, for each new element we introduce (x choose k) * 2**(x - k) where x is the total number of non fixed positions and k is the number that we need

    maybe everything I just said doesn't make sense

    Let's approach the problem differently

    What happens when there are multiple of the same element in a row?

    Well, if we know that the prefix median was equal to the first element, we keep having that same element be the prefix median by adding either possibility

    1111111 

    1*1*1*1*1*1

    * means that it could either be a 1 or a 0, no matter what the situation is 

    this is because there are always less possibilities for the inside element, so no matter what we put it will always be a good extension

    this means that there are 2 ** (k - 1) good extensions here

    after many of the same elements are there, what happens when you add something of the other element?

    11111110

    101010101010100

    in order for 0 to be the median, every one of the extensions also has to be a 0

    this means that there is only one possibility for this prefix

    now I assume we can just repeat this process of adding on the same character, as we know that the prefix only has one possibility no matter what because all the elements are fixed
*/
struct Mint {
    long long val;
    static const int MOD = 998244353;

    Mint(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    operator int() const { return val; }

    Mint operator+(const Mint &other) const {
        int res = val + other.val;
        if (res >= MOD) res -= MOD;
        return Mint(res);
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    Mint operator-(const Mint &other) const {
        int res = val - other.val;
        if (res < 0) res += MOD;
        return Mint(res);
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Mint operator*(const Mint &other) const {
        return Mint((val * 1LL * other.val) % MOD);
    }
    Mint& operator*=(const Mint &other) {
        val = (val * 1LL * other.val) % MOD;
        return *this;
    }

    Mint pow(long long exp) const {
        Mint base = *this, res = 1;
        while (exp > 0) {
            if (exp & 1) res *= base;
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    Mint inv() const {
        return pow(MOD - 2);
    }

    Mint operator/(const Mint &other) const {
        return *this * other.inv();
    }
    Mint& operator/=(const Mint &other) {
        *this *= other.inv();
        return *this;
    }
};

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    Mint ans = 1;
    int currlen = 1;
    for(int i = 1; i < n; i++){
        Mint result;
        if(s[i] == s[i-1]){
            Mint base = 2;
            result = base.pow(currlen);
            currlen++;
        }
        else{
            result = 1;
            currlen = 1;
        }
        ans += result;
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