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
    we have a string that represents a set

    count number of distinct
*/
 

// Small Observations
/*

*/
 

// Claims on algo 
/*  
    we can just simulate it by iterating over the string and actually adding to a set
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<char> x;
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ' ' && s[i] != ','){
            x.insert(s[i]);
        }
    }
    while(find(s.begin(), s.end(), ',') != s.end()){
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '{' && s[i] != '}' && s[i] != ' ' && s[i] != ','){
                x.insert(s[i]);
            }
        }
    }
    
    debug(x);
    cout << x.size() << '\n';

    return 0;
}