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
    directed acyclic graph

    you can ask queries

    in each query, you ask for the longest path in a set of elements that starts at a specific element

    find the longest possible path in 2 * n queries
*/
 

// Small Observations
/*
    each path starts somewhere, keeps going straight, and then stops when it reaches a node that doesn't have an outwards direction

    this seems very weird because he only tells you the length of the path

    something has to be special about the length of a path

    in 2 * n queries, you can probably get a lot of good information

    for example, you can find all the nodes that are adjacent to a current node in n-1 queries

    to figure out whether there is an edge between x and y, we can always do so with 1 query

    so we should use that type of query wisely when we need it

    what do we know about the longest path?

    it will always start somewhere that doesn't have any paths going into it, because otherwise it would start somewhere up the chain

    it will always end somewhere that doesn't have any paths going out of it

    it is similar to tree diameter in a way

    if we draw the path and then other nodes around it, we see that there may be other paths where one of the nodes on the path jumps to another one further down the path

    we can also see that other paths can go into nodes on the path, but the length of that path must be less than the length of the diameters path going into it

    if we choose a set of nodes and then query for each element within that set of nodes, the element we choose which has the longest path out of all of them in the set gives us the top

    if the set of nodes we choose has a path which is equal to the length of the set, we know that starting from the start node there is a direct path through all of them

    if we first query all the nodes and see that the length of the longest path is not equal to the number of nodes, we know there are some that we can remove from our set

    if we have multiple with the same path length, we should try removing all of them and see whether the longest path is still possible after removal

    only keep the one where the longest path is not still possible after removal

    the first check to find the starting point of the longest path should take n queries

    then it should take less than n queries to check all the other ones that have duplicate lengths

    this should work
*/
 

// Claims on algo 
/*  
    
*/

string query(int start, set<int> nums){
    string q;
    q += "? " + to_string(start) + ' ' + to_string(nums.size());
    for(int val : nums) q += " " + to_string(val);
    return q;
}

void test_case(){
    int n; cin >> n;
    vector<vector<int>> start_of_path_with_len(n + 1);
    set<int> vals;
    for(int i = 1; i <= n; i++) vals.insert(i);
    int max_len = 0;
    int start = -1;
    for(int i = 1; i <= n; i++){
        cout << query(i, vals) << '\n'; cout.flush();
        int len; cin >> len;
        start_of_path_with_len[len].push_back(i);
        if(len > max_len){
            max_len = len;
            start = i;
        }
    }
    
    for(int len = 1; len <= n; len++){
        vector<int> starts = start_of_path_with_len[len];
        if(len == max_len){
            for(int s : starts){
                if(s != start) vals.erase(s);
            }
            break;
        }
        if(starts.size() < 2) continue;
        vector<int> new_starts;
        for(int s : starts){
            set<int> new_set;
            for(int val : vals){
                if(val != s) new_set.insert(val);
            }
            cout << query(start, new_set) << '\n'; cout.flush();
            int len; cin >> len;
            if(len == max_len) vals.erase(s);
            else new_starts.push_back(s);
        }
        start_of_path_with_len[len] = new_starts;
    }
    string ans = "! " + to_string(max_len);
    for(int len = max_len; len > 0; len--) ans += " " + to_string(start_of_path_with_len[len][0]);
    cout << ans << '\n'; cout.flush();
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