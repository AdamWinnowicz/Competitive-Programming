#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& v, int target){
    int l = 0, r = v.size();
    while(l < r){
        int m = l + (r-l) / 2;
        if(v[m] <= target){
            l = m + 1;
        }
        else{
            r = m;
        }
    }
    return (l < v.size() && v[l] > target) ? l : -1;
}



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
        cout << upperBound(v,target) << '\n';
        // auto it = upper_bound(v.begin(),v.end(),target);
        // if(it != v.end()){
        //     cout << it - v.begin() << '\n';
        // }
        // else{
        //     cout << -1 << '\n';
        // }
    }

    return 0;
}