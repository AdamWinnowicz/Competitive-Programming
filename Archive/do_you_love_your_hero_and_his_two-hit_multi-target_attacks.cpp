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
    definitions

    p(a, b) is the distance between two points

    d(a, b) is the difference in x plus the difference in y (a different way to measure distance)

    we need to choose n distinct points so that exactly k pairs of the points have d(i, j) = p(i, j)

    output the n points that hold this property (constructive)
*/
 

// Small Observations
/*
    what causes regular distance to be equal to x distance plus y distance?

    think about it as a triangle

    if we take two points and take their x distance and y distance as sides of a triangle, we see that the hypotenuse is the direct distance

    this hypotenuse is guaranteed to be shorter than the sum of the x and y distances because it is a shorter path and that is required by triangle inequality

    however, there is one case in which the hyptonenuse is not the shorter path but instead an equal distance away

    if the two points share the same x coord or y coord, the triangle becomes a line, where the hypotenuse is equal to either the x dist or the y dist, and the corresponding dist in the other dir is 0

    this also fits with the formulas

    this means we need exactly k pairs of points such that they share either the same x coord or the same y coord

    how can we construct this

    start with a point at (0, 0)

    let's try to get all values of k

    k = 0 works if we put all points on a diagonal

    we can add a point at (1, 0) to make one pair k = 1

    then we can add a point at (0, 1) to make another pair k = 2

    one thing that might be important is that i < j for each pair, so when we add a new pair we pair it with all the values before only once

    .
    . .
    that shape can get us 1 or 2 pairs, depending on what we want

    let's try to avoid creating other pairs in any way

    .
    .
        .
        .
            .
            .
                .
                .
    we make one pair every time in this way

    therefore, with this algorithm we should be able to make as many pairs as necessary

    does it fit in 10**9 coords?

    yes, k is only up to 10**5 and we only move down by 2 for each pair, so 2*10**5 distance I guess

    however, this algo only works if n = 2 * k meaning we have enough to make every pair like this

    otherwise, we should try to make as many pairs as possible like this

    . . . . . . . . . . . .

    keep doing this until adding another would make the number of pairs greater than k

    then, do the same algo as earlier for the remaining few 

    oh, I just read the problem wrong lol

    we can use up to 500 staffs whenever we want

    does our algo work to get k = 10**5 with <= 500 staffs?

    if we place z in a line, we get z * (z-1) / 2 pairs

    so if we place 101 in a line we get 101 * 100 / 2 = 101 * 50 = 5050

    what if we place 401 in a line
    
    we get 401 * 400 / 2 = 401 * 200 = 80200 about 8 * 10 ** 4

    451 in a line = 451 * 450 / 2 = 451 * 225 = 101475 check!

    we can get as much as we need with this algo
*/
 

// Claims on algo 
/*  
    make a line starting at y = 0

    then raise it to y = 1

    keep going every time getting as much as possible
*/

void test_case(){
    int k; cin >> k;
    vector<pair<int,int>> ans;
    int cx = 0, cy = 0;
    int total_pairs = 0;
    while(total_pairs < k){
        ans.emplace_back(cx, cy);
        int will_make = 0;
        while(total_pairs + will_make + 1 <= k){
            will_make++;
            total_pairs += will_make;
            cx++;
            ans.emplace_back(cx, cy);
        }
        cx++;
        cy++;
    }
    assert(total_pairs == k);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
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