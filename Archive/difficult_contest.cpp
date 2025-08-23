#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    string s; cin >> s;
    string ans;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'T') ans+= 'T';
    }
    for(int i = 0; i < s.length(); i++){
        if(s[i] != 'T') ans+= s[i];
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