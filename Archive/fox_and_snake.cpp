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

    int n, m; cin >> n >> m;
    string prev = "left";
    for(int i = 0; i < n; i++){
        string row;
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                row += '#';
            }
        }
        else{
            if(prev == "left"){
                prev = "right";
                for(int j = 0; j < m - 1; j++){
                    row += '.';
                }
                row += "#";
            }
            else{
                prev = "left";
                row += "#";
                for(int j = 0; j < m - 1; j++){
                    row += '.';
                }
            }
        }
        cout << row << '\n';
    }

    return 0;
}