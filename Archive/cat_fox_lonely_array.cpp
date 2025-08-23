#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int max_dist = 0;
    for(int b = 0; b < 20; b++){
        vector<int> indices; indices.push_back(-1);
        for(int i = 0; i < n; i++){
            if(a[i] & (1 << b)){
                indices.push_back(i);
            }
        }
        indices.push_back(n);
        if(indices.size() == 2) continue;
        for(int i = 1; i < indices.size(); i++){
            int dist = indices[i] - indices[i-1] - 1;
            max_dist = max(dist, max_dist);
        }
    }
    cout << max_dist + 1 << '\n'; 
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