#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int l,r,d,u; cin >> l >> r >> d >> u;
        if(u == l && u == d && u == r) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}