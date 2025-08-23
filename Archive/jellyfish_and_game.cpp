#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    if(a[0] < b[m-1]) swap(a[0], b[m-1]); k--;
    // currently we have to play k more rounds
    // it is Gs turn - if we have an odd number of moves he will take the max
    // if we have an even number of moves the sum will remain the same
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    if(k % 2 == 1) swap(a[n-1], b[0]);

    ll total = 0;
    for(int val : a){
        total += val;
    }
    cout << total << '\n';
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