#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int evCount = 0, odCount = 0;
        int ev = 0; int od = 0;
        for(int i = 0; i < n; i+=2){
            if(a[i] == '0') odCount++;
            if(b[i] == '0') evCount++;
            od++;
        }
        for(int i = 1; i < n; i+=2){
            if(a[i] == '0') evCount++;
            if(b[i] == '0') odCount++;
            ev++;
        }
        if(evCount >= ev && odCount >= od){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }

    return 0;
}