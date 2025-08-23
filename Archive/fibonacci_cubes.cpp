#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> fib;
        fib.push_back(1); fib.push_back(2);
        for(int i = 2; i < n; i++){
            fib.push_back(fib[i-2] + fib[i-1]);
        }
        int x = fib[n-1], s = fib[n-2];
        string ans = "";
        for(int i = 0; i < m; i++){
            int w,l,h; cin >> w >> l >> h;
            if(w >= x && l >= x && h >= x && (w >= x+s || l >= x+s || h >= x+s)){
                ans += "1";
            }
            else{
                ans += "0";
            }
        }
        cout << ans << '\n';
    }

    return 0;
}