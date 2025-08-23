#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int ans = n;
        int inversions = 0;
        if(s[0] =='1') inversions++;
        for(int i = 0; i < n-1; i++){
            if((s[i] == '0' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')){
                inversions++;
            }
        }
        if(inversions < 2){
            ans += inversions;
        }
        else if(inversions == 2){
            ans += 1;
        }
        else if(inversions > 2){
            ans += inversions - 2;
        }
        cout << ans << '\n';
    }

    return 0;
}