#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    multiset<ll> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.insert(a[i]);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(b.find(a[i] * x) != b.end() && b.find(a[i]) != b.end()){
            b.erase(b.find(a[i] * x)); b.erase(b.find(a[i]));
        }
    }
    cout << b.size() << '\n';

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