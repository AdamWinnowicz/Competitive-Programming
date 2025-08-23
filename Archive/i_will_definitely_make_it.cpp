#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n, k; cin >> n >> k;
    vector<ll> h(n);
    
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll curr_height = h[k-1];
    ll water_height = 1;
    sort(h.begin(), h.end());
    for(int i = 0; i < n; i++){
        if(h[i] <= curr_height) continue;
        water_height += h[i] - curr_height;
        if(water_height - 1 > curr_height){
            return false;
        }
        curr_height = h[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}