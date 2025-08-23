#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int total = 0, make_positive = n;
        vector<int> occupied(31);
        for(int bit = 30; bit >= 0; bit--){
            if((1 << bit) & x){
                total += (1 << bit);
                make_positive--;
                occupied[bit]++;
            }
        }
        for(int bit = 0; bit <= 30; bit++){
            if(make_positive <= 0) break;
            int can_use = n - occupied[bit];
            if(can_use % 2 == 1) can_use--;
            int should_use = make_positive;
            if(make_positive % 2 == 1){
                if(should_use + 1 <= can_use) should_use++;
                else should_use--;
            }
            total += (1 << bit) * should_use;
            make_positive -= should_use;
        }
        if(total == 0){
            cout << -1 << '\n';
        }
        else{
            cout << total << '\n';
        }
    }
    return 0;
}