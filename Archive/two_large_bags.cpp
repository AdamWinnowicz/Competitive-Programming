#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n; cin >> n;
    vector<int> vals;
    map<int, int> count;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        count[val]++;
        if(count[val] == 1){
            vals.push_back(val);
        }
    }
    sort(vals.begin(), vals.end());
    int i = 0;
    while(i < vals.size()){
        if(i == vals.size()-1){
            return count[vals[i]] % 2 == 0;
        }
        int c1 = count[vals[i]], c2 = count[vals[i+1]];
        //cout << c1 << " " << c2 << " " << vals[i] << " " << vals[i+1] << '\n';
        if(c1 % 2 == 1 && (vals[i+1] - vals[i] > (c1/2))){
            return false; 
        }
        count[vals[i+1]] += max(0, c1 - 2 * (vals[i+1] - vals[i]));
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}