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
    given some numbers

    divide the numbers into the least groups possible

    such that no group has duplicates of the same bit
*/
 

// Small Observations
/*
    any time that a group has one element with the bit on and another with the bit off, you cannot add another element to the group

    the best thing you can do is make groups of 2

    this happens if one element is the exact opposite of the other in bitwise terms 

*/
 

// Claims on algo 
/*  
    we can check for this with each element by looking at the bits and constructing a number with the exact opposite bits
*/

void test_case(){
    int n; cin >> n;
    map<int,int> cnt;
    int ans = n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    set<int> used;
    for(const auto &p : cnt){
        int val = p.first;
        if(used.find(val) != used.end()) continue;
        int comp = 0;
        for(int b = 0; b < 31; b++){
            if((1 << b) & val){
                continue;
            }
            else{
                comp += (1 << b);
            }
        }
        int matches = min(cnt[val], cnt[comp]);
        used.insert(comp);
        ans -= matches;
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