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
    string s = "I hate "; 
    n--;
    int x = 1;
    while(n > 0){
        s += "that I ";
        if(x % 2 == 1){
            s += "love ";
        }
        else s += "hate ";
        n--;
        x++;
    }
    s += "it\n";
    cout << s << '\n';

    return 0;
}