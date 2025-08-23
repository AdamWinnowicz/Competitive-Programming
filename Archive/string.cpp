#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    string s; cin >> s;
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') count++;
    }
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}