#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll inversions(string s){
    ll ans = 0, n = s.length();
    ll one_count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') one_count++;
        else ans += one_count;
    }
    return ans;
}

void test_case(){
    int n; cin >> n;
    string s;
    ll one_count = 0, zero_count = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 1){
            s += '1';
            one_count++;
        }
        else{
            s += '0';
            zero_count++;
        }
    }
    ll ans = inversions(s);
    string one = s, two = s;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            one[i] = '1'; break;
        }
    }
    for(int i = n-1; i > -1; i--){
        if(s[i] == '1'){
            two[i] = '0'; break;
        }
    }
    ans = max(ans, inversions(one)); ans = max(ans, inversions(two));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case ? "Yes\n" : "No\n");
    }

    return 0;
}