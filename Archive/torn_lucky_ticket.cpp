#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    
    vector<vector<int>> cnt(6, vector<int>(46));
    vector<string> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        int sum = 0;
        for(char c : x[i]) sum += c - '0';
        cnt[x[i].length()][sum]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        string s = x[i];
        int m = s.length();
        for(int len = m % 2; len <= m && len < 6; len += 2){
            int half = (m + len) / 2;
            int left_sum = 0, right_sum = 0;
            for(int j = 0; j < half; j++){
                left_sum += s[j] - '0';
            }
            for(int j = half; j < m; j++){
                right_sum += s[j] - '0';
            }
            if(left_sum - right_sum > 0){
                ans += cnt[len][left_sum - right_sum];
            }
        }
        for(int len = m % 2; len < m && len < 6; len += 2){
            int half = (m + len) / 2;
            int left_sum = 0, right_sum = 0;
            for(int j = m - 1; j >= m - half; j--){
                right_sum += s[j] - '0';
            }
            for(int j = m - half - 1; j >= 0; j--){
                left_sum += s[j] - '0';
            }
            if(right_sum - left_sum > 0){
                ans += cnt[len][right_sum - left_sum];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}


// It was very difficult to understand what the problem was asking for when it talked about concatenation. 
// I thought that the order mattered, but it turned out to be unimportant.
// Both concatenations will always be possible because a pair does not need i < j
// Therefore order does not matter, so implementation is trivial
// One small issue with implementation was double counting the case of equal lengths
// This is necessary to avoid because we are trying to only consider pairs where the current string is the longer one
// When the lengths are the same, we don't want to count all the pairs with the same length twice both times that we loop
// Because (1, 2) and (2, 1) are unique pairs, we can order however we want so the only thing that matters is the length and sum
// This problem is super confusing, I still don't really understand it. Maybe I will understand it later
// Reason for double counting: if we loop over the ones of equal length a second time, we will consider all the pairs with itself a second time, where (1, 1) is not unique to (1, 1) (no ordering)
// What about equal length that are not in the same spot? 


