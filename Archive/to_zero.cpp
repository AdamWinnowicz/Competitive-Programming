#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n % 2 == 0){
            int ans = n / (k-1);
            int rem = n % (k-1);
            if(rem > 0) ans++;
            cout << ans << '\n';
        }
        else{
            int ans = 1;
            n -= k;
            ans += n / (k-1);
            int rem = n % (k-1);
            if(rem > 0) ans++;
            cout << ans << '\n';

        }
    }
    return 0;
}