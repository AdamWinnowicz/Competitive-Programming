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
    map<int, vector<int>> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        if(a[i] > b[i]) return false;
        bool possible = false;
        int l = i - 1, r = i + 1;
        while(l > -1){
            if(a[l] > b[i] || b[l] < b[i]) break;
            if(a[l] == b[i]){
                possible = true; break;
            }
            l--;
        }
        while(r < n){
            if(a[r] > b[i] || b[r] < b[i]) break;
            if(a[r] == b[i]){
                possible = true; break;
            }
            r++;
        }
        if(!possible) return false;
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