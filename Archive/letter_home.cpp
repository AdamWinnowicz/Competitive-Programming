#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(s <= a[0]){
            cout << a[n-1] - s << '\n';
        }
        else if(s >= a[n-1]){
            cout << s - a[0] << '\n';
        }
        else{
            cout << a[n-1] - a[0] + min(abs(s-a[0]), abs(s-a[n-1])) << '\n';
        }
        
    }

    return 0;
}