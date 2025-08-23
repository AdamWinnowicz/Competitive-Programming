#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> a(n);
    ll mx = 0, even_count = 0, mx_odd = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        if(a[i] % 2 == 0) even_count++;
        else mx_odd = max(mx_odd, a[i]);
    }
    if(even_count == n || even_count == 0){
        cout << 0 << '\n';
    }
    else{
        if(mx % 2 == 1){
            cout << even_count << '\n';
        }
        else{
            sort(a.begin(), a.end());
            bool needs_increase = false;
            for(int i = 0; i < n; i++){
                if(a[i] % 2 == 0){
                    if(mx_odd >= a[i]) mx_odd += a[i];
                    else{
                        needs_increase = true; break;
                    }
                }
            }
            if(needs_increase) even_count++;
            cout << even_count << '\n';
        }
        

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case ? "Yes\n" : "No\n");
    }

    return 0;
}