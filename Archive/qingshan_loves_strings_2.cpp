#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') one++;
        else zero++;
    }
    if(one != zero){
        cout << "-1\n"; return;
    }
    vector<int> operations;

    while(!s.empty()){
        string new_s;
        int l = 0, r = s.size()-1;
        while(l < r && s[l] != s[r]){
            l++; r--;
        }
        if(l > r){
            break;
        }
        if(s[l] == '0'){
            operations.push_back(r + 1);
            for(int i = 0; i <= r; i++) new_s += s[i];
            new_s += "01";
            for(int i = r + 1; i < s.size(); i++) new_s += s[i];
        }
        else{
            operations.push_back(l);
            for(int i = 0; i < l; i++) new_s += s[i];
            new_s += "01";
            for(int i = l; i < s.size(); i++) new_s += s[i];
        }
        s = new_s;
    }
    cout << operations.size() << '\n';
    for(int i = 0; i < operations.size(); i++){
        cout << operations[i] << (i == operations.size() - 1 ? "" : " ");
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