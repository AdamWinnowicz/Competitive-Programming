#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    // bubble sort
    bool possible = true;
    vector<pair<int,int>> swaps;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(a[j] > a[j+1]){
                if(b[j] < b[j+1]) possible = false;
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
                swaps.push_back({j+1, j+2});
            }
            else if(b[j] > b[j+1]){
                if(a[j] < a[j+1]) possible = false;
                swap(a[j], a[j+1]);
                swap(b[j], b[j+1]);
                swaps.push_back({j+1, j+2});
            }
        }
    }
    if(!possible){
        cout << -1 << '\n';
    }
    else{
        cout << swaps.size() << '\n';
        for(int i = 0; i < swaps.size(); i++){
            pair<int,int> x = swaps[i];
            cout << x.first << " " << x.second << '\n';
        }
    }
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