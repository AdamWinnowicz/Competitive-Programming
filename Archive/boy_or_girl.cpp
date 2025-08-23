#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    set<char> distinct;
    for(char c : s){
        distinct.insert(c);
    }
    if(distinct.size() % 2 == 0){
        cout << "CHAT WITH HER!" << '\n';
    }
    else{
        cout << "IGNORE HIM!" << '\n';
    }


    return 0;
}