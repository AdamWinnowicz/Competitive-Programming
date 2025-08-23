#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> nums;
    for(char c : s){
        if(c != '+'){
            nums.push_back(c - '0');
        }
    }

    sort(nums.begin(),nums.end());

    cout << nums[0];
    for(int i = 1; i < nums.size(); i++){
        cout << "+" << nums[i];
    }

    return 0;
}