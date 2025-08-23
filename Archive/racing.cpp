#include <bits/stdc++.h>
using namespace std;

pair<int,int> intersection(pair<int,int> p1, pair<int,int> p2){
    int a = p1.first, b = p1.second, c = p2.first, d = p2.second;
    int low = max(a,c), high = min(b,d);
    return {low, high};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> d(n);
        for(int i = 0; i < n; i++) cin >> d[i];
        vector<pair<int,int>> zone;
        for(int i = 0; i < n; i++){
            int l, r; cin >> l >> r;
            zone.push_back({l,r});
        }
        vector<pair<int,int>> possible;
        pair<int,int> currloc = {0,0};
        bool impossible = false;
        for(int i = 0; i < n; i++){
            if(d[i] == -1){
                currloc.second++;
            }
            else if(d[i] == 1){
                currloc.first++; currloc.second++;
            }
            pair<int,int> interval = zone[i];
            pair<int,int> intersect = intersection(currloc, interval);
            if(intersect.first > intersect.second){
                impossible = true;
                break;
            }
            possible.push_back(intersect);
            currloc = intersect;
        }
        if(impossible){
            cout << -1 << '\n';
            continue;
        }
        int currh = possible[n-1].second;
        for(int i = n-1; i > 0; i--){
            pair<int,int> last = possible[i-1];
            if(d[i] == -1){
                if(last.first <= currh - 1 && currh - 1 <= last.second){
                    d[i] = 1;
                    currh--;
                }
                else{
                    d[i] = 0;
                }
            }
            else if(d[i] == 1){
                currh--;
            }
        }
        if(d[0] == -1){
            if(currh - 1 == 0){
                d[0] = 1;
            }
            else{
                d[0] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            cout << d[i] << (i == n-1 ? "\n" : " ");
        }
    }

    return 0;
}