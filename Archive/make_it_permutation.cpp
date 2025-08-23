#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << 2 * n - 2 << '\n';
        cout << 1 << " " << 1 << " " << n << '\n';
        cout << 2 << " " << 2 << " " << n << '\n';
        for(int i = 3; i <= n; i++){
            cout << i << " " << 1 << " " << i-1 << '\n';
            cout << i << " " << i << " " << n << '\n';
        }
    }
    

    return 0;
}