#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        for(int i = 1; i < s.length(); i++){
            int at_least = 9 - i;
            int best_ind = i, best_val = s[i] - '0';
            for(int j = i+1; j < s.length(); j++){
                int val = s[j] - '0';
                if(val < best_val && val >= at_least){
                    best_val = val; best_ind = j;
                }
            }
            swap(s[i],s[best_ind]);
        }
        cout << s << '\n';
    }

    return 0;
}