#include <bits/stdc++.h>
using namespace std;

void generate_permutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if(start == nums.size()){
        result.push_back(nums);
        return;
    }
    for(int i = start; i < nums.size(); i++){
        swap(nums[i], nums[start]);
        generate_permutations(nums, start + 1, result);
        swap(nums[i], nums[start]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i;
    vector<vector<int>> perms;
    generate_permutations(a, 0, perms);
 
    for(const auto &perm : perms){
        for(int val : perm) cout << val << " ";
        cout << '\n';
    }
    return 0;
}