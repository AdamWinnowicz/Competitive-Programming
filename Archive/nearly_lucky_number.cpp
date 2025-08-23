#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int count = 0;
    for(char num : s){
        if (num == '4' || num == '7'){
            count++;
        }
    }
    string x = to_string(count);
    bool valid = true;
    for(char c : x){
        if (c == '4' || c == '7'){
            continue;
        }
        else{
            valid = false;
        }
    }
    if(valid){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}