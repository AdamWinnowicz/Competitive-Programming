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
    given array

    find minimum number of removed elements

    such that every element has a count of C (or zero)
*/
 

// Small Observations
/*
    we can always remove every element to get an empty array, so it is always possible

    that also means our upper bound on answer is n

    
*/
 

// Claims on algo 
/*  
    if any count is currently smaller than c, we have to remove all of them

    if any count is currently greater than c, we have to remove cnt - c of them

    this should give us the number of necessary removals, and it also accounts for removing all because that is only necessary when all counts are less than c

    this solves the problem for a fixed c

    what if c can be anything

    we could try every c but it would take o(n**2) so too long

    could we say that our goal is the largest value of c? 

    not necessarily, because that could require removing a lot of elements

    we can start with c being the maximum count

    we would have to remove all groups that don't have that count

    then we can consider c being the next largest count

    this means we have to remove all the elements that had a greater count, but we don't have to remove the groups with the size of the current c

    this could be good

    we can proabably do a full loop to check all of this, where c is going from 0 to the max count but jumping only by counts that exist

    this is o(nlogn) with sorted set of counts

    in order to know how much stuff changes, we also need to maintain a map which is the count of counts, or in other words the number of times an element with this count appears

    if we look at the sorted array of counts, the number that we can keep is equal to the current count * the length of the suffix
*/

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for(int & x : a){
        cin >> x;
        cnt[x]++;
    }
    vector<int> b;
    for(const auto & p : cnt){
        b.push_back(p.second);
    }
    sort(b.begin(), b.end());
    int can_keep = 0;
    int m = b.size();
    for(int i = 0; i < m; i++){
        int C = b[i];
        int suff_len = m - i;
        can_keep = max(can_keep, C * suff_len);
    }
    int ans = n - can_keep;
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