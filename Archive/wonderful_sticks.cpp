#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> need;
    for(int i = 1; i <= n; i++) need.push_back(i);
    vector<int> ans(n);
    int l = 0, r = n-1;
    for(int i = n-2; i > -1; i--){
        if(s[i] == '<'){
            ans[i+1] = need[l];
            l++;
        }
        else{
            ans[i+1] = need[r];
            r--;
        }
    }
    ans[0] = need[l];
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "\n" : " ");
    }
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