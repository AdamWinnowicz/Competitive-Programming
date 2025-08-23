#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, j, k; cin >> n >> j >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(k >= 2) cout << "YES\n";
    else{
        cout << (a[j-1] == *max_element(a.begin(), a.end()) ? "YES\n" : "NO\n");
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