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
    count the number of subsequences of length k (odd) in a binary array where 1 appears more than 0
*/
 

// Small Observations
/*
    first, let's call the number of ones - number of zeros in a subsequence as the balance of the subsequence

    if balance is positive, the subsequence has median of 1 (which is what we want)

    lets consider one subsequence of length k - 1 (even)

    if the balance is negative, any subsequence of length k formed from all of the other elements would be bad

    if the balance is 0, the number of valid subsequences of length k formed by adding other elements is equal to the number of ones

    if the balance is positive, number of valid is equal to the number of other elements (n - k)

    one thing that we can do is check the number of ones

    in a subsequence of length k that is good, it must have at least (k + 1) / 2 ones

    lets say we take (k + 1) / 2 ones from arbitrary positions out of the ones

    for any arrangement of (k + 1) / 2 ones, we can choose all the other elements to make an array of length k arbitrarily and cover all cases with ones that are greater than (k + 1) / 2 in one check

    the remaining k / 2 elements can be chosen in every way possible out of the remaining n - (k + 1) / 2 elements, so we can use n choose k to compute

    idea:

    we know the number of ones and the number of zeros in the total array

    in order for the subarray to be good, it must have at least (k + 1) / 2 ones

    to determine the answer, consider all the ways to choose (k + 1) / 2 ones and n - (k + 1) / 2 zeros

    then we can keep doing that but including all the ways to choose more ones until we get to the number of ones or k

    our answer is the sum of all those choosing
*/
 

// Claims on algo 
/*  
    implement the above idea
*/
struct Mint {
    long long val;
    static const int MOD = 1e9 + 7;

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

Mint fact[200005];

Mint n_choose_k(int n, int k){
    if(k > n) return 0;
    return fact[n] / (fact[n - k] * fact[k]);
}

void test_case(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1) ones += 1;
        else zeros += 1;
    }
    Mint ans = 0;
    for(int v = (k + 1) / 2; v <= min(k, ones); v += 1){
        Mint ones_arrangement = n_choose_k(ones, v);
        Mint zeros_arrangement = n_choose_k(zeros, k - v);
        ans += ones_arrangement * zeros_arrangement;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = fact[1] = 1;
    for(Mint i = 2; i < 200005; i += 1){
        fact[int(i)] = fact[int(i)-1] * i;
    }

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}