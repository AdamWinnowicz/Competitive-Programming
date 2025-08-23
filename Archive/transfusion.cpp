#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >>n;
    vector<int> a(n);
    ll odd_sum = 0, even_sum = 0;
    ll odd_count = 0, even_count = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i % 2 == 0){
            even_sum += a[i];
            even_count++;
        }
        else {
            odd_sum += a[i];
            odd_count++;
        }
    }
    cout << ((odd_sum % odd_count == 0 && even_sum % even_count == 0 &&
    odd_sum / odd_count == even_sum / even_count) ? "YES\n" : "NO\n");
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