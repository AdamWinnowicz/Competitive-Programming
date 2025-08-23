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
    given a perm

    count min ops to make it simple

    simple means pi = i or ppi = i
*/
 

// Small Observations
/*
    if it was just pi = i, that means identity perm

    once pi = i, we can ignore it

    the first condition is actually covered by the first!

    if pi = i, then p(pi) = pi 

    this means that the only condition we care about is ppi = i

    for each i, find the min ops to make ppi = i

    there are two ways we can do it

    either change pi to the location of i

    or change the element at pi to i

    if we change pi to the location of i

    5 1 3 2 4

    2 1 3 5 4

    it can resolve multiple mismatches in one move

    5 1 3 2 4

    1 5 3 2 4
    
    1 2 3 5 4

    this takes two moves if we try to make identity perm 

    Can we think about this like a graph?

    lets try another approach

    identity perm works

    1 2 3 4 5 6 ...

    what can we do to this and it will still work?

    3 2 1 4 5 6 

    this swap keeps the property

    3 4 1 2 5 6

    still good

    3 4 1 2 6 5
    
    still good

    how does it break?

    2 4 1 3 6 5

    now there is a swap which doesn't match up with locations (elements 2 and 3 were swapped when they werent on indices 2 and 3)

    this means we need one operation to get back to good perm

    we could find this by trying to move 3 to the 2 position because 1 is at position 3

    how could we make it take more operations?

    2 4 1 5 6 3

    if we move 3 in now, bad stuff happens

    3 4 1 5 6 2

    3 6 1 5 4 2

    well, not really

    the idea of moving the location in seems to work well

    can we do it in less than 2 operations?

    2 4 1 5 6 3

    no

    to do it in one operation, first we need to resolve the first number so that either pi = i or ppi = i

    we can either put 1 there

    1 4 2 5 6 3

    it still isn't good

    or we can

    2 4 1 5 6 3

    3 4 1 5 6 2

    it also still isn't good

    what if we do this

    2 4 1 5 6 3

    2 1 4 5 6 3

    still not good

    how can we think of this mathematically

    we need to make the current index good

    in which way can we do it that guarantees the best situation in the future?

    im stuck, think of something else

    OH 

    in order to be good

    a pair of indices i, j

    has either i, j or j, i in those indices
    
    THIS IS BAD

    WHY AM I SO STUCK

    THINKKKKKKKKKKKKKKKKKK


    idea

    becuase swapping indices only changes those two indices, that operation is independent from other operations

    this means you can choose greedily

    the best option every time is to move the value that is the current location of i to i

    this ensures that both i and pi are good locations

    if instead we try to move the good element there, we only make one location good


*/
 

// Claims on algo 
/*  
    because we never revist locations that became good, we can just store the initial locations of each thing and swap in the array accordingly when necessary
*/

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int,int> loc;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        loc[a[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == i + 1 || a[a[i] - 1] == i + 1) continue;
        ans++;
        int curr_loc = loc[i + 1];
        int needed = loc[curr_loc + 1];
        swap(a[i], a[needed]);
        loc[a[i]] = i;
        loc[a[needed]] = needed;

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