#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    set<int> seen;
    int first = 0;
    for(int i = 0; i < m; i++){
        if(!seen.count(b[i])){
            if(a[first] == b[i]){
                first++; seen.insert(b[i]);
            }
            else{
                cout << "TIDAK\n"; return;
            }
        }
    }
    cout << "YA\n";
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