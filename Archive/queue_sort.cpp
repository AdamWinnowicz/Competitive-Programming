#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    int mn = 1e9 + 5;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    int start = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == mn){
            start = i; break;
        }
    }
    bool possible = true;
    for(int i = start + 1; i < n; i++){
        if(a[i] < a[i-1]){
            possible = false;
            break;
        }
    }
    if(!possible){
        cout << -1 << '\n';
    }
    else{
        cout << start << '\n';
    }
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