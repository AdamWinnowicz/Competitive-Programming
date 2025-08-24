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
    n running tracks

    each running track has ai segments of equal length

    you are given a value u

    if there are ai sections

    you add u, u - 1, u - 2, u - 3, ... u - ai + 1

    you are also given a value l, which is the start index of a subarray of tracks

    you want to choose to end the subarray at the smallest r where increase in performance is maximum possible

    we also have to answer queries of l and u
*/
 

// Small Observations
/*
    we can only use at most log(n) ops per query bc n is up to 10**5 and q is up to 10**5

    probably something with binary search

    all the matters is the total number of sections that he covers

    lets call the total number of sections s

    that means we would add u + u - 1 + u - 2 + ... + u - s + 1

    if we just went from left to right starting at l, we would keep extending the subarray and adding to s

    however, once s becomes equal to u, we should stop

    this would mean that our sum is always positive without adding negative elements

    because the smallest addition would be u - u + 1 = 1

    if s became u + 1, we would still be ok, but we want to minimize r

    if s became u + 2, we start subtracting from the sum which is bad

    this means that we only have to check two sums (if they both exist)

    the largest sum which is smaller than u

    and the first sum which is larger than u

    any sum before the largest which is smaller than u will be missing out

    any sum after the first sum which is larger than u will be smaller

    in this way, we just have to check which of these is better

    if the value of the further left one is >= the value of the right one, we choose the left one

    otherwise we choose the right one
*/
 

// Claims on algo 
/*  
    how do we find the first sum greater than u? use binary search on the prefix sum

    once we find that index (if it exists), we check its pref sum and the previous pref sum

    then we output r accordingly

    first sum greater than u means first sum starting at l which is greater than u

    pref[r] - pref[l - 1] > u

    pref[r] > u + pref[l - 1]
*/

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int & x : a) cin >> x;
    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    int q; cin >> q;
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int l, u; cin >> l >> u; l--;
        int prefl = (l == 0 ? 0 : pref[l - 1]);
        auto it = upper_bound(pref.begin(), pref.end(), u + prefl);
        if(it == pref.end()){
            ans[i] = n - 1;
        }
        else{
            int ind = it - pref.begin();
            if(ind > 0 && ind - 1 >= l){
                // choose both options ind - 1 and ind
                ll sum1 = pref[ind - 1] - prefl;
                ll sum2 = pref[ind] - prefl;
                ll val1 = (2*u - sum1 + 1) * sum1 / 2;
                ll val2 = (2*u - sum2 + 1) * sum2 / 2;
                if(val1 >= val2){
                    ans[i] = ind - 1;
                }
                else ans[i] = ind;
            }
            else{
                ans[i] = ind;
            }
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] + 1 << (i == q-1 ? "\n" : " ");
    }
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