#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x = n / 15;
        int r = n % 15;
        int ans = 0;
        if(r < 3) ans = 3*x + r + 1;
        else ans = 3*(x+1);
        cout << ans << '\n';
        
    }

    return 0;
}