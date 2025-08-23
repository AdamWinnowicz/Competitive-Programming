#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int buffer = ((n-k) % 2 == 0 ? (n-k)/2 - 1 : (n-k) / 2);
        cout << a[n-1-buffer] - a[buffer] + 1 << '\n';
    }

    return 0;
}