#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    int x = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s.length() <= m){
            m -= s.length();
            x++;
        }
        else m = 0;
    }
    cout << x << '\n';
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