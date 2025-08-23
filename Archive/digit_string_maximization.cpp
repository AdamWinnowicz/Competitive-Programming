#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void modify_string(string& s, int n, int start){
    int best_index = start, best_digit = s[start] - '0';
    for(int i = start + 1; i < start + 9 && i < n; i++){
        int digit = s[i] - '0' - (i - start);
        if(digit > best_digit){
            best_digit = digit;
            best_index = i;
        }
    }
    if(best_index == start) return;
    vector<char> shift_right;
    for(int i = start; i < best_index; i++){
        shift_right.push_back(s[i]);
    }
    s[start] = best_digit + '0';
    for(int i = start + 1; i <= best_index; i++){
        s[i] = shift_right[i - start - 1];
    }
}

void test_case(){
    string s; cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        modify_string(s, n, i);
    }
    cout << s << '\n';
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