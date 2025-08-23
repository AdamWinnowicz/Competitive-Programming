#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int i = 0;
    while(a[i] == 'B' && b[i] == 'B') i++;
    if(i == n) return true;
    bool bottom = (b[i] == 'B');
    while(i < n){
        if(a[i] == 'B' && b[i] == 'B') bottom = !bottom;
        else if(a[i] == 'B'){
            if(bottom) return false;
        }
        else if(b[i] == 'B'){
            if(!bottom) return false;
        }
        i++;
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