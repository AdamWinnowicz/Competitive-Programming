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
        for(int i = 0; i < n-1; i++){
            if(abs(a[i]-a[i+1]) <= 1){
                found = true;
            }
        }
        if(found) cout << 0 << '\n';
        else{
            bool good = false;
            for(int i = 1; i < n-1; i++){
                if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])){
                    good = true;
                    break;
                }
            }
            if(good) cout << 1 << '\n';
            else{
                cout << -1 << '\n';
            }
        }
        
    }

    return 0;
}