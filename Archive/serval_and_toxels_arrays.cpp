#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> cnt(n + m + 1, 0LL);
    map<ll, ll> last_ind;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        last_ind[a[i]] = -1LL;
    }
    ll ans = 0;
    ll f = 0;
    for(ll i = 0; i < m; i++){
        ll p, v; cin >> p >> v; p--;
        ll curr = a[p];
        if(curr != v){
            last_ind[v] = i;
            cnt[curr] += i - last_ind[curr];
        }
        ll could_see = i + 1;
        ll no_v = could_see - cnt[v], no_curr = could_see - cnt[curr];
        ll diff = no_v - no_curr;
        f += n + diff;
        ans += f;
        a[p] = v;
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

// Takeaways:
// When dealing with problems with constraints and a fixed set of given changes, try to find what is similar between the states
// In this problem, because we can only change one element at a time, we can see the difference between one step and the next
// ... because this difference is small, it is easy to do case work and determine what is the same and what is different by just looking at it

// Specifically, the state of an array changes by only one element - removing a distinct element for another distinct element
// This means that we can easily see how the value changes from state to state
// When a new element is added, it can be better or worse than the element that was already there
// Now we just need to figure out what difference it makes
// The next array will pair with all previous arrays and the current array it came from
// The number of distinct for each pair including the next array will be almost the same as the number of distinct from the current array for each pairing
// The only difference is that we know longer have a distinct element x, and we have a new distinct element y
// The number of times that y does not occur in previous arrays is the contribution to value over all pairings that adding y makes
// Because we also remove x, if x did not occur in previous arrays then we no longer have its contribution, so we must subtract it.

// Important: we need to maintain the counts of each element at each state
// We can't loop through everything in O(n * m), so we need a smart way to keep track
// Key:
// We only update the count of some element when we remove it
// Why? An element will always remain unchanged (present) if it was present originally, so it will appear every time unless we remove it
// When we remove it, it can stay away for a period of time and then it can reappear, where we should make a start index again to track it
// Then when we remove it again we can keep track of the count

// Why don't we always need the count of every element?
// The only elements we need the count of is the element that we are changing and the element that we are adding
// We can update the count of the element we are changing right as we find that we are changing it
// ... The element that we are adding cannot already be in the array, because the elements must be unique, that means that
// it must either never have been in the array or that it was but was later removed, and we would have updated the count at that time

// Additional Takeaway:
// I got lucky that I was able to notice a fast way to keep track of the count - without it you cannot solve the problem
// This problem shows an important idea of using past cases to determine the effect of the next one - some form of dp