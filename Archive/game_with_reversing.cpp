#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) a++;
        if(s[i] != t[n-i-1]) b++;
    }
    if(a % 2 == 0){
        a *= 2;
    }
    else{
        a = a * 2 - 1;
    }
    if(b % 2 == 1){
        b *= 2;
    }
    else{
        if(b == 0) b = 2;
        else b = b * 2 - 1;
    }
    cout << min(a, b) << '\n';
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