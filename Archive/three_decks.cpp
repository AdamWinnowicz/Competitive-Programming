#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a,b,c; cin >> a >> b >> c;
        int total = a+b+c;
        if(total % 3 != 0){
            cout << "NO\n";
            continue;
        }
        int val = total / 3;
        if(a > val || b > val){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }

    }

    return 0;
}