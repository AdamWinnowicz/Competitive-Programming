#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int ind = 0;
        int ans = 0;
        for(int i = n-1; i > -1; i--){
            if(s[i] != '0'){
                ind = i;
                break;
            }
            else ans++;
        }

        for(int i = 0; i < ind; i++){
            if(s[i] != '0') ans++;
        }
        cout << ans << '\n';

    }

    return 0;
}