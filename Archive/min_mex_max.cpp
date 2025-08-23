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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 2; i++){
        set<int> x;
        for(int j = i; j < i + 3; j++){
            if(a[j] != -1) x.insert(a[j]);
        }
        if(x.size() > 1) return false;
        if(x.size() == 1){
            for(int j = i; j < i + 3; j++){
                a[j] = *x.begin();
            }
        }
        if(x.find(0) != x.end()) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "YES\n" : "NO\n");
    }

    return 0;
}