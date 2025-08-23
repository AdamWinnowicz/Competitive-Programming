#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        vector<string> names;
        for(int i = 0; i < n; i++){
            string name;
            cin >> name;
            names.push_back(name);
        }
        vector<int> power;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            power.push_back(p);
        }
        while (names.size() > 1) {
            vector<string> victors;
            vector<int> new_power;
            for(int i = 0; i < names.size()-1; i+=2){
                int p1 = power[i], p2 = power[i+1];
                if(p1 > p2){
                    victors.push_back(names[i]);
                }
                else if(p1 < p2){
                    victors.push_back(names[i+1]);
                }
                else{
                    victors.push_back(names[i] + names[i+1]);
                }
                new_power.push_back(p1+p2);
            }
            names = victors;
            power = new_power;
        }
        cout << names[0] << '\n';
    }

    return 0;
}