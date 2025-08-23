#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0' || s[i] == 'e'){
            ll count = 0;
            for(int j = i; j < n; j += (i+1)){
                if(s[j] == '0'){
                    s[j] = 'e'; count++;
                }
                else if(s[j] != 'e') break;
            }
            ans += (i+1) * count;
        }
    }
    cout << ans << '\n';
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