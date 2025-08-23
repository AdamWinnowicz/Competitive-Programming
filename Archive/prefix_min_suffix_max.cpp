#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // if the value a[i] is the minimum of its prefix or the maximum of its suffix, it can be done
    vector<int> min_pref, max_suff;
    min_pref.push_back(a[0]);
    for(int i = 1; i < n; i++){
        min_pref.push_back(min(a[i], min_pref.back()));
    }
    max_suff.push_back(a[n-1]);
    for(int i = n-2; i > -1; i--){
        max_suff.push_back(max(a[i], max_suff.back()));
    }
    reverse(max_suff.begin(), max_suff.end());
    string ans = "";
    for(int i = 0; i < n; i++){
        if(a[i] == max_suff[i] || a[i] == min_pref[i]){
            ans += "1";
        }
        else ans += "0";
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