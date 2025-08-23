#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') count++;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '0') ans += count + 1;
        else ans += count - 1;
    }
    cout << ans << '\n';
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