#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> a(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            total += a[i];
        }
        if(total % n == 0 && total / n == x){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}