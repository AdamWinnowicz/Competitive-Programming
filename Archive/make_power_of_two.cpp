#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

vector<string> pt;

void test_case(){
    string s; cin >> s;
    int n = s.length();
    int ans = n + 1;
    for(string p : pt){
        //debug(p);
        int same = 0, len = p.length();
        int ind = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == p[ind]) ind++;
        }
        int moves = (n - ind) + (len - ind);
        ans = min(ans, moves);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 65; i++){
        pt.push_back(to_string((1LL << i)));
    }

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}