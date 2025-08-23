#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        double B,H; cin >> B >> H;
        vector<double> y;
        for(int i = 0; i < n; i++){
            double height; cin >> height;
            y.push_back(height);
        }
        double ans = 0.0;
        for(int i = 0; i < n - 1; i++){
            double h = y[i+1] - y[i];
            if (h >= H){
                ans += B * H / 2;
            }
            else{
                h = H - h;
                double total = B * H / 2;
                double b = B * h / H;
                total -= b * h / 2;
                ans += total;
            }

        }
        ans += B * H / 2;
        cout << fixed << setprecision(6) << ans << '\n';
    }

    return 0;
}