#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n; cin >> n;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    // pa < pc, pb > pd
    // fix a and c
    // precompute the number of values pd where pd < pb in the interval [b+1, n]
    vector<ll> f(n);
    for(int b = 1; b < n - 2; b++){
        for(int d = b + 1; d < n; d++){
            if(p[d] < p[b]) f[b]++;
        }
    }
    vector<ll> prefix_f(n);
    ll ans = 0;
    // iterate over a and c
    // also iterate over possible values of b and check if pb > pc which is the extra case
    for(int c = 2; c < n - 1; c++){
        for(int b = 1; b < c; b++){
            if(p[b] > p[c]) f[b]--;
        }
        for(int i = 1; i < n; i++){
            prefix_f[i] = prefix_f[i-1] + f[i];
        }
        for(int a = 0; a < c - 1; a++){
            if(p[a] < p[c]){
                ans += prefix_f[c - 1] - prefix_f[a];
            }
        }
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

// key takeaways:
// When optimizing solutions from higher complexity such as O(n**4) down to O(n**2), think about how you can remove each loop or fix specific
// elements of the loop

// What I did well:
// - was able to come up with a working solution
// - was able to optimize memory to pass

// What I should improve next time:
// - if I see that n**2 = 2.5 * 10**7, I should avoid using n**2 memory
// - sometimes there are interesting techniques you can use to save memory
// - the initial approach may use extra memory when you can really store in a different way

// This technique:
// We realize that there is an issue with overcounting
// We have some values that tell us the count of something in the prefix after an element
// We want to see a range instead -- without using extra memory / 2d prefix/suffix sums
// How can we subtract on the go instead of using prefix sums?
// - the key is that we iterate over all end points at least once
// - we can keep the complexity n**2 and put a non-nested loop to subtract the extras in the range
// - we want to maintain f so that it doesn't have elements in the current range from a + 1 to c - 1
// -- that means we need to subtract (somehow, possible over time) the times where condition is met
// --- we should subtract from f for each pair where the condition is met within the range (up to c)
// --- since we iterate over c, we can get all pairs by iterating over b for every c and making sure that they don't have the condition
// --- this ensures we have all the pairs in the subarray from 1 to c accounted for, modifying f(b) accordingly
// --- with everything maintained, we can use as little as o(n) memory instead of o(n**2).