#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        long long n,m; cin >> n >> m;
        bool make_root = true;
        if(m < n || m > n*(n+1)/2){
            cout << -1 << '\n';
            continue;
        }
        while(m >= 2*n){
            if (make_root) {
                cout << n << '\n';
                make_root = false;
            } else {
                cout << n+1 << " " << n << '\n';
            }
            m -= n;
            n--;
        }
        int diff = m-n+1;
        if (make_root) {
            cout << diff << '\n';
        } else {
            cout << n+1 << " " << diff << '\n';
        }
        int prev = diff;
        for(int j = 1; j <= n; j++){
            if(j == diff) continue;
            cout << prev << " " << j << '\n';
            prev = j;
        }
    }
    return 0;
}