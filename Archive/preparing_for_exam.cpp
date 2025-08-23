#include <bits/stdc++.h>
using namespace std;

void test_case(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(m);
    set<int> knows;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        int val; cin >> val; knows.insert(val);
    }
    set<int> doesnt_know;
    for(int i = 1; i <= n; i++){
        if(knows.find(i) == knows.end()){
            doesnt_know.insert(i);
        }
    }
    string ans = "";
    if(doesnt_know.size() == 0){
        for(int i = 0; i < m; i++) ans += "1";
    }
    else if(doesnt_know.size() == 1){
        for(int i = 0; i < m; i++){
            if(a[i] == *doesnt_know.begin()){
                ans += "1";
            }
            else ans += "0";
        }
    }
    else{
        for(int i = 0; i < m; i++) ans += "0";
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