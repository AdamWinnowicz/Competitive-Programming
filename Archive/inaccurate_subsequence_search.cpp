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
    
*/
 
// Small Observatins
/*
 
 
*/
 
 
// Claims on algo 
/*  
    We can use a sliding window to keep track of the current subarray and the number of elements it contains that can also be found in b
 
    As we slide, element that we lose might be part of the elements in b, so we lose one
 
    The new element that we gain could help us, or maybe not
 
    How do we know whether an element can help or hurt? 
 
    We can keep a counter of the elements not currently occupied from b in a map
 
    If there are still any elements left of a specific val, when we get that val we can increase the current number of good elements 
 
    When we lose a val if we were using it (decreasing the good elements when we lose it) the counter increases again
 
*/
void test_case(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    map<int,int> cnt;
    for(int& x : b){
        cin >> x;
        cnt[x]++;
    }
    map<int,int> ocnt = cnt;
    map<int,int> num_in_range;
    int ans = 0;
    int good = 0;
    for(int i = 0; i < m; i++){
        num_in_range[a[i]]++;
        if(cnt[a[i]] > 0){
            cnt[a[i]]--;
            good++;
        }
    }
    if(good >= k) ans++;
    for(int i = m; i < n; i++){
        num_in_range[a[i-m]]--;
        if(num_in_range[a[i-m]] < ocnt[a[i-m]]) good--;
        num_in_range[a[i]]++;
        if(num_in_range[a[i]] <= ocnt[a[i]]) good++;
        if(good >= k) ans++;
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