#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        if(k == 1){
            long long ans = a[0] + a[n-1];
            if(n > 2){
                ans = max(ans, 1LL * *max_element(a.begin()+1, a.end()-1) + max(a[0], a[n-1]));
            }
            cout << ans << '\n';
        }
        else{
            sort(a.begin(), a.end(), greater<int>());
            long long ans = 0;
            for(int i = 0; i <= k; i++) ans += a[i];
            cout << ans << '\n';
        }
    }
    return 0;
}
