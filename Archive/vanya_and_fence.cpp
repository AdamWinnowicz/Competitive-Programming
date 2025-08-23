#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h; cin >> n >> h;
    vector<int> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if(val > h) ans += 2;
        else ans += 1;
    }
    cout << ans << '\n';

    return 0;
}