#include <bits/stdc++.h>
using namespace std;

long long best_size(long long top, long long bottom, long long left, long long right){
    long long s1 = (top - bottom + 1);
    long long s2 = (right - left + 1);
    long long total = s1 * s2;
    return total + min(s1, s2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int,int>> coords;
        long long top = 1, bottom = 1000000000, left = 1000000000, right = 1;
        vector<int> on_top, on_bottom, on_left, on_right;
        for(int i = 0; i < n; i++){
            long long x,y; cin >> x >> y;
            top = max(top, y); bottom = min(bottom, y); left = min(left, x); right = max(right, x);
            coords.push_back({x,y});
        }
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        long long ans = (top - bottom + 1) * (right - left + 1);
        for(int i = 0; i < n; i++){
            long long x = coords[i].first, y = coords[i].second;
            if(y == top) on_top.push_back(i);
            if(y == bottom) on_bottom.push_back(i);
            if(x == left) on_left.push_back(i);
            if(x == right) on_right.push_back(i);
        }
        for(int i = 0; i < n; i++){
            long long x = coords[i].first, y = coords[i].second;
            long long new_top = 1, new_bottom = 1000000000, new_left = 1000000000, new_right = 1;
            if(on_top.size() == 1 && on_top[0] == i){
                for(int j = 0; j < n; j++){
                    long long y = coords[j].second;
                    if(y != top) new_top = max(new_top, y);
                }
            }
            else{
                new_top = top;
            }
            if(on_bottom.size() == 1 && on_bottom[0] == i){
                for(int j = 0; j < n; j++){
                    long long y = coords[j].second;
                    if(y != bottom) new_bottom = min(new_bottom, y);
                }
            }
            else{
                new_bottom = bottom;
            }
            if(on_right.size() == 1 && on_right[0] == i){
                for(int j = 0; j < n; j++){
                    long long x = coords[j].first;
                    if(x != right) new_right = max(new_right, x);
                }
            }
            else{
                new_right = right;
            }
            if(on_left.size() == 1 && on_left[0] == i){
                for(int j = 0; j < n; j++){
                    long long x = coords[j].first;
                    if(x != left) new_left = min(new_left, x);
                }
            }
            else{
                new_left = left;
            }
            if((new_top - new_bottom + 1) * (new_right - new_left + 1) == n - 1){
                ans = min(ans, best_size(new_top, new_bottom, new_left, new_right));
            }
            else ans = min(ans, (new_top - new_bottom + 1) * (new_right - new_left + 1));
        }

        cout << ans << '\n';
    }
    


    return 0;
}