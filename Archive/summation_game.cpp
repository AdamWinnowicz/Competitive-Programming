#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < x; i++){
        sum -= 2 * a[i];
    }
    int ans = sum, currsum = sum;
    for(int i = 0; i < k; i++){
        if(i+x < n){
            currsum -= 2 * a[i+x];
        }
        currsum += a[i];
        ans = max(ans, currsum);
    }
    cout << ans << '\n';
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