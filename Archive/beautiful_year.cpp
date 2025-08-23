#include <bits/stdc++.h>
using namespace std;

bool distinct_digits(string num){
    set<char> digits;
    for(int i = 0; i < num.length(); i++) digits.insert(num[i]);
    return digits.size() == num.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int y; cin >> y;
    while(true){
        y++;
        if(distinct_digits(to_string(y))){
            cout << y << '\n';
            return 0;
        }
    }

    return 0;
}