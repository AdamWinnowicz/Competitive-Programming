#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,m,p,q;
        cin >> n >> m >> p >> q;
        if(n % p == 0){
            int total = (n / p) * q;
            if(m == total){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}