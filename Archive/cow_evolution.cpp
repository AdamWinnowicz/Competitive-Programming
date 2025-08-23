#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    int n;
    cin >> n;
    map<string,set<int>> leaves;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            string trait;
            cin >> trait;
            leaves[trait].insert(i);
        }
    }

    vector<string> traits;
    for(auto& p : leaves) traits.push_back(p.first);

    for(int i = 0; i < traits.size(); i++){
        for(int j = i+1; j < traits.size(); j++){
            set<int> a = leaves[traits[i]], b = leaves[traits[j]];
            bool intersects = false, unique_in_a = false, unique_in_b = false;
            for(int x : a){
                if(b.count(x)){
                    intersects = true;
                }
                else{
                    unique_in_a = true;
                }
            }
            for(int x : b){
                if(!a.count(x)){
                    unique_in_b = true;
                }
            }
            if(intersects && unique_in_a && unique_in_b){
                cout << "no\n";
                return 0;
            }
        }
    }
    cout << "yes\n";
    return 0;
}