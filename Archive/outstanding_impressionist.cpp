#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    map<int,int> fixed_count;
    vector<pair<int,int>> ranges;
    vector<int> fixed(2*n+1);
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        ranges.push_back({l,r});
        if(l == r){
            fixed_count[l]++;
            fixed[l] = 1;
        }
    }
    vector<int> prefsum(2*n+1);
    int total = 0;
    for(int i = 0; i < 2*n+1; i++){
        total += fixed[i];
        prefsum[i] = total;
    }
    for(auto [l,r] : ranges){
        cout << (l == r ? fixed_count[l] == 1 : prefsum[r] - prefsum[l-1] != r - l + 1);
    }
    cout << '\n';
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