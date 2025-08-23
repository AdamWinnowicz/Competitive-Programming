#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MEX(set<int> vals, int n){
    int ans = 0;
    for(int i = 0; i <= n+1; i++){
        if(vals.find(i) == vals.end()){
            ans = i;
            break;
        }
    }
    return ans;
}
void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    set<int> vals;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        vals.insert(a[i]);
    }
    int mex = MEX(vals, n);
    map<int,int> count;
    for(int i = 0; i < n; i++){
        if(a[i] <= mex){
            count[a[i]]++;
        }
    }
    map<int, vector<int>> vx;
    for(const auto&p : count){
        vx[p.second].push_back(p.first);
    }
    vx[0].empty();
    set<int> valid = {mex};
    for(int k = 0; k <= n; k++){
        vector<int> now_valid = vx[k];
        for(int val : now_valid){
            valid.insert(val);
        }
        valid.erase(n - k + 1);
        cout << valid.size() << (k == n ? "\n" : " ");
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