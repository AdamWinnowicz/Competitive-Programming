#include <bits/stdc++.h>
using namespace std;

bool binarySearch(const vector<int>& v, int target){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(v[m] == target){
            return true;
        }
        else if(v[m] < target){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return false;
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
        if(binarySearch(v,target)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}