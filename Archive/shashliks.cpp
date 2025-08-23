#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int k,a,b,x,y; cin >> k >> a >> b >> x >> y;
        int ans = 0;
        if(x < y){
            if(k >= a){
                int portions = (k-a) / x + 1;
                k -= x * portions;
                ans += portions;
            }
            if(k >= b){
                int portions = (k-b) / y + 1;
                k -= y * portions;
                ans += portions;
            }
        }
        else{
            if(k >= b){
                int portions = (k-b) / y + 1;
                k -= y * portions;
                ans += portions;
            }
            if(k >= a){
                int portions = (k-a) / x + 1;
                k -= x * portions;
                ans += portions;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}