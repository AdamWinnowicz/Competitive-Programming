#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 1;
        int currelem = a[0];
        for(int i = 1; i < n; i++){
            if (a[i] > currelem + 1){
                currelem = a[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}