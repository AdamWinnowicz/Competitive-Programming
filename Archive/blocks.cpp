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
    int b = 0, w = 0;
    for(int i = 0; i < n; i++){
        b += (s[i] == 'B');
        w += (s[i] == 'W');
    }
    if(b % 2 == 1 && w % 2 == 1){
        cout << "-1\n"; return 0;
    }
    if(b == 0 || w == 0){
        cout << 0 << '\n'; return 0;
    }
    int i = 0;
    vector<int> ops;
    char c = (b % 2 == 0 ? 'W' : 'B');
    while(i < n){
        if(s[i] == c) {
            i++; continue;
        }
        ops.push_back(i + 1);
        if(s[i] == s[i+1]){
            i += 2;
        }
        else{
            swap(s[i], s[i+1]); i++;
        }
    }
    cout << ops.size() << '\n';
    for(int i = 0; i < ops.size(); i++){
        cout << ops[i] << (i == ops.size() - 1 ? "\n" : " ");
    }

    return 0;
}