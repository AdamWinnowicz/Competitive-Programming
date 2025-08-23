#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll m1 = 0, m2 = 0, positive = 0, negative = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1 && b[i] == 1) positive++;
        else if(a[i] == 1) m1++;
        else if(b[i] == 1) m2++;
        else if(a[i] == -1 && b[i] == -1) negative++;
    }
    if(m2 < m1) swap(m2, m1);
    if(positive > (m2 - m1)){
        positive -= (m2 - m1); m1 = m2;
    }
    else{
        m1 += positive; positive = 0;
    }
    if(negative > (m2 - m1)){
        negative -= (m2 - m1); m2 = m1;
    }
    else{
        m2 -= negative; negative = 0;
    }
    m1 += positive / 2 - negative / 2; m2 += positive / 2 - negative / 2;
    if(negative % 2 == 1 && positive % 2 == 0) m1--;
    cout << min(m1, m2) << '\n';

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