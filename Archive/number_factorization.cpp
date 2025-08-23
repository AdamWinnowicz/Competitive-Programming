#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void test_case(){
    int n; cin >> n;
    map<int, vector<int>> power;
    ll multiple = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0 && i <= n){
            int p = 0;
            while(n % i == 0 && n > 0){
                p++;
                n /= i;
            }
            power[p].push_back(i);
            multiple *= i;
        }
    }
    multiple *= n;
    power[1].push_back(n);
    ll ans = 0, used = 0;
    for(const auto& p : power){
        ll true_power = p.first - used;
        ans += multiple * true_power;
        for(int factor : p.second){
            multiple /= factor;
        }
        used = p.first;
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