#include <bits/stdc++.h>
using namespace std;

bool solve(string s){
    int count = 0;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == '('){
            count++;
        }
        else{
            count--;
        }
        if(count < 1){
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(solve(s)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}