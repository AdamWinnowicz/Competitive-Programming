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
 

// Small Observations
/*
    
*/
 

// Claims on algo 
/*  
    
*/

void test_case(){
    string s; cin >> s;
    int n = s.length();
    vector<string> ans;
    for(int i = 0; i < n; i++){
        if(s[i] != '0'){
            string curr; curr += s[i];
            int ind = i + 1;
            while(ind < n){
                curr += '0';
                ind++;
            }
            ans.push_back(curr);
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
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