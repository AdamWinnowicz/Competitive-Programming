#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

// Problem Statement
/*
    we have a grid

    get from 0, 0 to n, n

    can move right or up

    path has n segments at most

    for each of the segments, there is a cost associated

    cost is multiplied by the length

    find the minimum cost
*/
 

// Small Observations
/*
    in order to reach (n, n), we need to travel a total of n units to the right and n units to the left

    this means we have to travel a total of 2 * n units

    if the cost was 1 for everything, it would cost 2 * n to reach the end

    now we know that there are some different costs for different segments

    if there is a minimum cost, we should try to travel as much distance as possible on that segment

    however, we cannot just travel all of our distance on that segment

    this is because the cost is for the ith segment, meaning that there were i - 1 segments beforehand and half of those have to be going the same direction we are going now

    also, when we travel longer on one segment, we give less leeway to the other segment to change its position

    idea:
    
    look at the even and odd indices of the array, and consider them independent because they represent the two different directions arbitrarily

    4 3 2 1 4

    even = 4 2 4

    odd = 3 1

    we know that at even indices we have to spend a total of n

    we know that at odd indices we have to also spend n

    knowing this, where should we spend it to have the minimum cost?

    we want to spend as much as we can at the minimum

    however, in order to reach the minimum you still need to spend extra for each segment

    we see that the minimum of even indices is 2, which occurs at index 2

    we see that the minimum of odd indices is 1, which occurs at index 3

    because of this, we can spend 1 * 4 + 4 * 2 on even and 3 * 1 + 4 * 1 on odd, for a total of 12 + 7 = 19

    however, this heuristic probably doesn't always work, because sometimes it might be better to stay at a value rather than spend to get to another value

    We need a way to consider all the possibilities as we loop through the array

    Maybe we can try to consider ending the set of segments at each point, meaning that we will cover all the possibilities of number of segments from 2 segments to n segments

    If we try to end at index i (1-based), we will have i segments

    We can look at the odd and even indices of these segments and find the optimal arrangement of these segments for cost purposes

    The greedy assumption is that if you have to choose x segments, x-1 of them should have a length of only 1, and then the minimum should have a length of n - x

    we have to do this for both the odd and even indices

    however, we can probably use the result of a previous prefix to find the result of the current prefix in O(1)

    First, look at the parity of the index we are adding

    Then, see whether it is smaller than the minimum of the previous prefix

    if it is larger or equal, we need to add the difference between the current cost and that of the minimum, because we add the current cost and subtract the minimum cost because we move it

    if it is smaller, we have a new minimum

    so we should check how many were at the old minimum and move all but one of them to the new minimum

    this means that we decrease the cost by the difference between the current and old minimum cost times the number of times we are able to do so

    we can simulate this for all numbers of segments using this greedy hueristic and update the answer to be the minimum
*/
 

// Claims on algo 
/*  
    
*/

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll even_min = a[0], odd_min = a[1];
    ll even_min_cnt = n, odd_min_cnt = n;
    ll ans = a[0] * n + a[1] * n;
    ll curr_cost = ans;
    //debug(even_min, odd_min, curr_cost);
    for(int i = 2; i < n; i++){
        if(i % 2 == 0){
            even_min_cnt--;
            if(a[i] >= even_min){
                curr_cost += (a[i] - even_min);
            }
            else{
                curr_cost -= (even_min - a[i]) * even_min_cnt;
                even_min = a[i];
            }
        }
        else{
            odd_min_cnt--;
            if(a[i] >= odd_min){
                curr_cost += (a[i] - odd_min);
            }
            else{
                curr_cost -= (odd_min - a[i]) * odd_min_cnt;
                odd_min = a[i];
            }
        }
        //debug(curr_cost);
        ans = min(ans, curr_cost);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}