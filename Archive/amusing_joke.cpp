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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b, c; cin >> a >> b >> c;
    unordered_map<char, int> cnt1, cnt2;
    for(char x : a) cnt1[x]++;
    for(char x : b) cnt1[x]++;
    for(char x : c) cnt2[x]++;
    for(char x = 'A'; x <= 'Z'; x++){
        if(cnt1[x] != cnt2[x]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}