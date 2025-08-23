#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    ll mx = a[0];
    ll rest = 0;
    for(int i = 1; i < n; i++) rest += a[i];
    //cout << mx << " " << rest << '\n';
    if(mx > rest){
        cout << mx - rest << '\n';
    }
    else if(mx == 0){
        cout << 0 << '\n';
    }
    else{
        cout << 1 << '\n';
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