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
    we have an array of numbers

    we have a value h

    at any moment, we can take any element with value less than h and delete it, adding ai / 2 to h

    at any moment, we can double h, but we can only do this a total of two times

    at any moment, we can triple h, but we can only do this once
*/
 

// Small Observations
/*
    at the start, we should always take any elements with value of less than h

    this is because we can only ever add ai / 2 from an element when we get rid of it, but we should try to add elements before multiplying to get more out of them

    if we write the current value as h + ai / 2 + aj / 2 + ak / 2 etc

    if we multiply all of these by any value x, we get x * h + x * ai / 2 + x * aj / 2 + x * ak / 2

    basically, we multiply by every number that we already added

    if we multiplied any time before adding these elements, we wouldn't multiply those values that we added, which is worse

    therefore, we should always add as much as we can and then multiply as needed

    how should we multiply?

    what products can we get from 2, 2, and 3

    2, 3, 4, 6, 12

    once we reach a value which is greater than or equal to h, we can see what we need to multiply h by to make it greater than ai

    should we multiply by the smallest amount possible? I think so

    This is because if we multiply by the smaller amount, we save the other factors for multiplication in the future which ensures that they multiply by more numbers, which is good as we demonstrated earlier

    Therefore, we can continue this process until we cannot make h greater than the current value of ai

    we should always be looking at the smallest values of ai not yet used to get the most out of them

    unfortunately, this greedy algorithm does not work 

    even though it seems to help, multiplication is weird

    when you have two numbers that are closer together and multiply them (with the same sum) it is always better than further apart with the same sum

    for example, 4 * 4 = 16 > 3 * 5 = 15

    because of this, choosing the smallest number every time is not always the best

    because there are so few numbers, we can quickly run through all subsets to try all possibilities, maintaining the greedy idea of adding before multiplying

    one way to check all possibilites would be to consider all permutations of 2, 2, 3

    in this way, we would loop through this permutation and multiply by the current value of the permutation when necessary

    each time we do this, we update answer with the amount we were able to get from our trial
*/
 

// Claims on algo 
/*  
    complete the above process
*/

void test_case(){
    ll n, h; cin >> n >> h;
    vector<ll> a(n);
    for(ll & x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> multiples = {2, 2, 3};
    ll ans = 0;
    do {
        ll curr_ans = 0;
        ll p = 0;
        ll curr_h = h;
        for(int i = 0; i < n; i++){
            if(curr_h > a[i]){
                curr_h += a[i] / 2;
                curr_ans++;
            }
            else{
                while(curr_h <= a[i] && p < 3){
                    curr_h *= multiples[p];
                    p++;
                }
                if(curr_h <= a[i]) break;
                curr_ans++;
                curr_h += a[i] / 2;
            }
        }
        ans = max(ans, curr_ans);
    } while(next_permutation(multiples.begin(), multiples.end()));
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