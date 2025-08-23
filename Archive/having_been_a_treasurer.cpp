#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int l = 0, x = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '_') l++;
            else x++;
        }
        if(x % 2 == 0){
            cout << 1LL * (x/2) * (x/2) * l << '\n';
        }
        else{
            cout << 1LL * (x/2) * (x/2+1) * l << '\n';
        }
    }

    return 0;
}