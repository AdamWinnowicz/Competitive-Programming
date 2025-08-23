#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        bool found = false;
        if((a[0] == 0 && a[1] == 0) || (a[n-2] == 0 && a[n-1] == 0)){
            cout << "YES\n";
            continue;
        }
        for(int i = 1; i < n-1; i++){
            if((a[i-1] == 0 && a[i] == 0) || (a[i] == 0 && a[i+1] == 0)){
                cout << "YES\n";
                found = true;
                break;
            }
        }
        if(found) continue;
        if(count(a.begin(),a.end(),1) == n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}