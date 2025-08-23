#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    vector<ll> dp(n + 1);
    dp[n] = 0;
    ll ans = 0;
    for(int i = n-1; i > -1; i--){
        auto it = upper_bound(pref.begin(), pref.end(), x + (i == 0 ? 0LL : pref[i-1]));
        int j = it - pref.begin();
        dp[i] = (j == n ? j - i : dp[j + 1] + j - i);
        ans += dp[i];
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

// what do I learn from this?
// when you want to find a dp state, look at what is similar between the cases

// I had the right idea when it comes to trying to keep track of the number of valid segments starting/ending at an index

// I had the right idea about the pattern being caused by reaching greater than x in the sum

// I didn't know how to iterate so that I could update this
// Next time, try to determine which way things happen
// Because the changes go from left to right and g is added from left to right, dp[i] uses the values of dp[j] where j is greater than i, so we should
// iterate from the end to be able to update properly

// New technique: binary searching over prefix sums to find the first sum that is greater than something

// I was able to determine the idea but not implement at the end

// Final takeaway:
// When you know it is dynamic programming, you need to see how the subproblems overlap
// Try to see in which direction they overlap so you know how to iterate
// !!! DO THE MATH FIRST - Don't worry about complexity
// In easy problems there is always a quick way to find things, so don't stress if you know you have to find an index with a property
// ... finish the math and deal with finding the necessary things efficiently when you get to them