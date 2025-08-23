#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int a_count = 0, d_count = 0;
    for(char c : s){
        if(c == 'A'){
            a_count++;
        }
        else{
            d_count++;
        }
    }
    if(a_count > d_count){
        cout << "Anton\n";
    }
    else if(a_count < d_count){
        cout << "Danik\n";
    }
    else{
        cout << "Friendship\n";
    }

    return 0;
}