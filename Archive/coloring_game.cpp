#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int s = max(a[j]-a[i], a[n-1] - a[i] - a[j]);
                int x = upper_bound(a.begin(),a.begin()+i,s) - a.begin();
                ans += i - x;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}