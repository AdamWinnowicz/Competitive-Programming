#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> next_one(n), prev_zero(n);
    int prev = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') prev = i;
        prev_zero[i] = prev;
    }
    int nxt = n;
    for(int i = n-1; i > -1; i--){
        if(s[i] == '1') nxt = i;
        next_one[i] = nxt;
    }
    set<pair<int,int>> mods;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r; l--; r--;
        if(s[l] == '0') l = next_one[l];
        if(s[r] == '1') r = prev_zero[r];
        if(l < r){
            mods.insert({l, r});
        }
        else{
            mods.insert({1, 1});
        }
    }
    cout << mods.size() << '\n';
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