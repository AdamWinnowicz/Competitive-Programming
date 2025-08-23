#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    set<int> vals;
    map<int,int> last_location;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        last_location[a[i]] = i+1;
        vals.insert(a[i]);
    }
    int ans = -1;
    for(int val : vals){
        for(int i = 1; i <= 1000; i++){
            if(vals.find(i) != vals.end() && __gcd(val, i) == 1){
                ans = max(ans, last_location[val] + last_location[i]);
            }
        }
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