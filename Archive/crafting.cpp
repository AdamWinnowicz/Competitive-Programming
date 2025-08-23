#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int less_count = 0, diff = 0, skip = 0;
        for(int i = 0; i < n; i++){
            if(b[i] > a[i]){
                less_count++;
                diff = b[i] - a[i];
                skip = i;
            }
        }
        if(less_count == 0){
            cout << "YES\n";
        }
        else if(less_count == 1){
            int buffer = 1000000001;
            for(int i = 0; i < n; i++){
                if(i != skip) buffer = min(buffer, a[i]-b[i]);
            }
            cout << (buffer >= diff ? "YES\n" : "NO\n");
        }
        else cout << "NO\n";

        



    }

    return 0;
}