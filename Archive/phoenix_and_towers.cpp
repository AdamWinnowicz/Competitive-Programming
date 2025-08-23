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
    we have some towers of height less than x

    we want to make m towers by stacking some on top of each other

    find a possible arrangement of towers where the final difference in heights is no more than x
*/
 

// Small Observations
/*
    what does it mean that the heights are all less than x?

    if we stack one tower on top of an already existing one, we raise its height by less than x

    when would stacking a tower on top of another be bad?

    if the new difference between the stacked tower and the smallest tower is greater than x

    what happens if we always add less than x to the smallest tower from a set of towers that differs by less than x

    it will still differ by less than x
*/
 

// Claims on algo 
/*  
    therefore, lets just choose m towers arbitrarily because we already know that they differ by less than x

    then take the remaining towers and add them to the smallest one each time

*/

struct cpair {
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }
};

void test_case() {
    int n, m, x; cin >> n >> m >> x;
    vector<int> a(n);
    for(int & x : a) cin >> x;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cpair> pq;
    vector<int> ans(n);
    for(int i = 0; i < m; i++){
        pq.push({a[i], i + 1});
        ans[i] = i + 1;
    }
    for(int i = m; i < n; i++){
        pair<int,int> p = pq.top();
        int sum = p.first, ind = p.second;
        ans[i] = ind;
        sum += a[i];
        pq.pop();
        pq.push({sum, ind});
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n - 1 ? "\n" : " ");
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