#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll sum = 0, odd_count = 0;
    for(int k = 0; k < n; k++){
        sum += a[k];
        if(a[k] % 2 == 1) odd_count++;
        ll val = sum;
        if(k != 0){
            ll olya = odd_count / 3;
            ll rem = odd_count % 3;
            val -= olya;
            if(rem == 1) val--;
        }
        cout << val << (k == n-1 ? "\n" : " ");
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