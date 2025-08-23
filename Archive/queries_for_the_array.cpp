#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    string s; cin >> s;
    int len = 0;
    int first_unsorted = 2 * 1e5 + 5, last_sorted = 1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            if(len >= first_unsorted) return false;
            last_sorted = max(1, len);
        }
        else if(s[i] == '0'){
            if(len <= last_sorted) return false;
            first_unsorted = min(first_unsorted, len);
        }
        else if(s[i] == '+'){
            len++;
        }
        else{
            len--;
            if(len < last_sorted){
                last_sorted = max(1, last_sorted-1);
            }
            if(len < first_unsorted){
                first_unsorted = 2 * 1e5 + 5;
            } 
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}