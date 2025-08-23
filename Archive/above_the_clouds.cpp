#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        set<char> seen;
        bool found = false;
        for(int i = 1; i < n-1; i++){
            if(seen.find(s[i]) != seen.end() || s[i] == s[0] || s[i] == s[n-1]){
                found = true; break;
            }
            seen.insert(s[i]);
        }
        if(found){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}