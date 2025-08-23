#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> digits;
        bool found = false;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            digits[a[i]]++;
            if(digits[0] >= 3 && digits[2] >= 2 && digits[1] >= 1 && digits[3] >= 1 && digits[5] >= 1){
                found = true;
                cout << i+1 << '\n';
                break;
            }
        }
        if(!found){
            cout << 0 << '\n';
        }
    }

    return 0;
}