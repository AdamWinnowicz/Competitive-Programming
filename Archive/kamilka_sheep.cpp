#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int mx = 0, mn = 1000000001;
        for(int i = 0; i < n; i++){
            int val; cin >> val;
            mx = max(mx, val);
            mn = min(mn, val);
        }
        cout << mx - mn << '\n';
        
    }

    return 0;
}