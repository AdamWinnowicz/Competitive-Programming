#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, x, y; cin >> a >> x >> y;
        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        if(x < a && a < y){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}