#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> a(n);
        int mn = n, mx = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1){
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        if(x > mx - mn){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }

    return 0;
}