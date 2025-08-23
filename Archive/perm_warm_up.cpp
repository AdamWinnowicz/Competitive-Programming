#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int total = 0;
        for(int i = 1; i <=n; i++){
            total += abs(i - (n-i+1));
        }
        cout << total / 2 + 1 << '\n';
    }

    return 0;
}