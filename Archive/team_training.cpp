#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(),a.end(), greater<int>());
        int ans = 0;
        int currlen = 0, Min = a[0];
        for(int i = 0; i < n; i++){
            Min = min(a[i], Min);
            currlen++;
            if(Min * currlen >= x){
                currlen = 0;
                Min = 1000000000 + 1;
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}