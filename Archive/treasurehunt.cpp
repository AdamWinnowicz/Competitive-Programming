#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int x, y, a; cin >> x >> y >> a;
        int rem = a % (x+y);
        if(rem >= x){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}