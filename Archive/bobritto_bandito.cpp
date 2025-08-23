#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m,l,r; cin >> n >> m >> l >> r;
        while(n > m){
            if(r > 0) r--;
            else l++;
            n--;
        }
        cout << l << " " << r << '\n';
    }

    return 0;
}