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
    vector<int> a(n), b(n);
    for(int& x : a){
        cin >> x;
    }
    for(int & x : b){
        cin >> x;
    }
    if(a[n-1] != b[n-1]) return false;
    for(int i = n-2; i > -1; i--){
        if(a[i] == b[i]) continue;
        if((a[i] ^ a[i+1]) != b[i] && (a[i] ^ b[i+1]) != b[i]) return false;
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