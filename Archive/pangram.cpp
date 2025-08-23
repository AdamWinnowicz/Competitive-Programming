#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    set<char> d;
    for(int i = 0; i < n; i++){
        d.insert(tolower(s[i]));
    }
    if(d.size() == 26){
        cout << "YES\n";
    }
    else cout << "NO\n";

    return 0;
}