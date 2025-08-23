#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> b(2 * n);
    vector<ll> a(2 * n + 1);
    for(int i = 0; i < 2*n; i++) cin >> b[i];
    sort(b.begin(), b.end(), greater<int>());
    a[0] = b[0];
    a[2*n] = b[1];
    int ind = 2;
    a[2*n-1] = b[0] + b[1];
    for(int i = 1; i < 2*n-1; i+=2){
        a[i+1] = b[ind]; ind++;
        a[i] = b[ind]; ind++;
        a[2*n-1] += a[i+1] - a[i];
    }
    for(int i = 0; i < 2*n+1; i++){
        cout << a[i] << (i == 2*n ? "\n" : " ");
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