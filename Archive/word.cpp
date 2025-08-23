#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int ucount = 0, lcount = 0;
    for(char c : s){
        if(isupper(c)){
            ucount++;
        }
        else{
            lcount++;
        }
    }
    if(ucount > lcount){
        for(int i = 0; i < s.length(); i++){
            s[i] = toupper(s[i]);
        }
    }
    else{
        for(int i = 0; i < s.length(); i++){
            s[i] = tolower(s[i]);
        }
    }
    cout << s << '\n';

    return 0;
}