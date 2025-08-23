#include <bits/stdc++.h>
using namespace std;

// int lowerBound(const vector<int>& v, int target){
//     int l = 0, r = v.size();
//     while(l < r){
//         int m = l + (r - l) / 2;
//         if(v[m] >= target){
//             r = m;
//         }
//         else{
//             l = m + 1;
//         }
//     }
//     if(l < v.size() && v[l] == target){
//         return l;
//     }
//     else{
//         return -1;
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        int target;
        cin >> target;
        // cout << lowerBound(v,target) << '\n';
        auto it = lower_bound(v.begin(),v.end(),target);
        if(*it == target){
            cout << it - v.begin() << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}