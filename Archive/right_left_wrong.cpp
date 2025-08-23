#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> prefsum(n+1, 0);
    ll total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
        prefsum[i+1] = total;
    }
    string s; cin >> s;
    int l = 0, r = n-1;
    ll ans = 0;
    while(l < r){
        if(s[l] == 'L' && s[r] == 'R'){
            ans += (prefsum[r+1] - prefsum[l]);
        }
        if(s[l] != s[r]){
            l++; r--;
        }
        else if(s[l] == 'L' && s[r] == 'L'){
            r--;
        }
        else{
            l++;
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