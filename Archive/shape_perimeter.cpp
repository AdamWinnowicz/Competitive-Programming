#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int p = 4 * m;
        int x, y; cin >> x >> y;
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            p += 2 * x + 2 * y;
        }
        cout << p << '\n';
    }

    return 0;
}