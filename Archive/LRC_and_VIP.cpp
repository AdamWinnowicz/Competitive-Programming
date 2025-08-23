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
        int mx = *max_element(a.begin(),a.end());
        if(count(a.begin(),a.end(),a[0]) == n){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                if(a[i] == mx){
                    cout << "1";
                }
                else{
                    cout << "2";
                }
                if(i < n-1) cout << " ";
            } 
            cout <<'\n';
        }
    }
    return 0;
}