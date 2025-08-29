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
    we can make two lists with the numbers from 1 to n appearing either in the first or second list

    we will make ri queries for the number i

    let's call the location of the number i in the list j (1 indexed)

    if the number is in the first list, the query will take j * s1 seconds 

    if the number is in the second list, it will take j * s2 seconds

    minimize the cost
*/
 

// Small Observations
/*
    what can we optimize?

    why don't we just put all the numbers in the list that takes less time?

    because once the position becomes larger, it may take more seconds to reach that position than if it was at the start of the other list

    the first thing that we can do is sort by the cost r[i], and consider those with the largest costs first

    then we can use two pointers to check whether putting it at the front of the first list is better or the second list

    the way to check this is to see the relationship between s1 * ind1 and s2 * ind2
*/
 

// Claims on algo 
/*  
    implement the above idea
*/

void test_case(){
    ll n, s1, s2; cin >> n >> s1 >> s2;
    vector<pair<ll,ll>> info;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        info.emplace_back(x, i);
    }
    sort(info.begin(), info.end(), [](pair<ll,ll> a, pair<ll,ll> b){
        return a.first > b.first;
    });
    vector<ll> a, b;
    ll al = 0, bl = 0;
    for(int i = 0; i < n; i++){
        ll a_cost = s1 * (al + 1), b_cost = s2 * (bl + 1);
        if(a_cost <= b_cost){
            a.push_back(info[i].second + 1);
            al++;
        }
        else{
            b.push_back(info[i].second + 1);
            bl++;
        }
    }
    cout << al;
    for(int i = 0; i < al; i++){
        cout << " " << a[i];
    }
    cout << '\n';
    cout << bl;
    for(int i = 0; i < bl; i++){
        cout << " " << b[i];
    }
    cout << '\n';

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