#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        int n1 = s1.length(), n2 = s2.length();
        int i = 0, j = 0;
        bool possible = true;
        while(i < n1 && j < n2){
            char c = s1[i];
            int c1 = 0, c2 = 0;
            while(i < n1 && s1[i] == c){
                i++; c1++;
            }
            while(j < n2 && s2[j] == c){
                j++; c2++;
            }
            if(c2 > 2*c1 || c1 > c2){
                possible = false;
                break;
            }
        }
        if(possible && j == n2 && i == n1) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}