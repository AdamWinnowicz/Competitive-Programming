#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    string s; cin >> s;
    sort(s.begin(), s.end());
    cout << s[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}