#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[n-1] == '1') return true;
    int count = 0, one_count = 0;
    for(int i = 0; i < n-1; i++){
        if((s[i] == '0' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')){
            count++;
        }
        if(s[i] == '1') one_count++;
    }
    if(count / 2 >= one_count){
        return false;
    }
    else return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        //test_case();
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}