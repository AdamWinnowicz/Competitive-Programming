#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        int total = 0;
        int currcost = 1;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == 'T'){
                total += currcost;
                currcost = 1;
            }
            else{
                currcost *= 2;
            }
        }
        cout << total << '\n';
    }

    return 0;
}