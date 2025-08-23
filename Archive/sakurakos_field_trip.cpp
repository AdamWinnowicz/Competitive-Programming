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
    array a

    minimize number of adjacent elements that are equal

    swap ith and n - i + 1th elements
*/
 

// Small Observations
/*
    when you swap ith and n - i + 1th elements, what happens?
    
    starting from the outside

    1 1 2 2

    if we swap the outside elements, we remove 2 adjacent equalities

    1 1 3 4 4 2 2 1 1 1 1 5 3

    can we always just consider swapping the elements furthest outside as independent?

    if we swap the elements on the outside, we get the best that we can do with the current situation

    if we then also swap the elements on the inside, we might lose that which we gain but possibly gain more on the more inner elements

    that's why you should only swap if the amount you gained from the last operation is less than the amount you will gain from the current operation

    iterate from left to right and keep track of the amount you gained on the last operation and compare with the amount you can gain

    you can either not swap, gaining 0 on the current operation and keep the amount you gained from the last one

    or you can remove the amount you gained from the last one

    what if you didn't swap the last element?

    then you have to consider whether you create more bad things by swapping or not

    the key is that you can only change the elements in the specific areas

*/
 

// Claims on algo 
/*  
    does greedily swapping work?

    when you swap, what can you gain?

    1 1 2 2 --> 1 2 1 2 you can gain 2

    1 2 2 1 --> you can gain zero because you cannot change anything

    obs: if elements are the same, you cannot do anything by swapping them

    if elements are different and there are currently two equalities on the outsides, swapping them will always be good

    why? you can always swap the inside elements as well however you want to get the best situation, no matter the orientation of the outside elements

    this means we can just swap greedily based on whether the swap makes less pairings with outside elements

    at the end we can just count the adj 
*/

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i < n && n - i - 1 > i; i++){
        if(a[i] == a[n-i-1]) continue;
        if(a[i-1] == a[i] || a[n-i-1] == a[n-i]){
            swap(a[i], a[n-i-1]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += (a[i] == a[i+1]);
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