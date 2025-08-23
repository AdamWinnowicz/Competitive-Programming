#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b; cin >> a >> b;
    string c;
    for(int i = 0; i < a.length(); i++){
        if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')){
            c += '1';
        }
        else c += '0';
    }
    cout << c << '\n';

    return 0;
}