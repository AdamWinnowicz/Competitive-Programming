#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

string substring(int start, int end, string s){
    string ans;
    for(int i = start; i <= end; i++) ans += s[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int l = 1, r = n - 1;
    bool found = false;
    while(l <= r){
        string t = substring(l, r, s);
        string x = substring(0, r - l, s);
        string y = substring(r-l+1, r, s);
        if(t == x){
            for(int i = 0; i < k-1; i++){
                s += y;
            }
            found = true;
            break;
        }
        l++;
    }
    if(!found){
        string copy = s;
        for(int i = 0; i < k-1; i++){
            s += copy;
        }
    }
    cout << s << '\n';

    return 0;
}