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
    construct a permutation of integers from 1 to n

    all odd indices 1, 3, 5 (1 indexed) are done with bitwise & on k

    all even indices 2, 4, 6 are done with bitwise or on k

    maximize k
*/
 

// Small Observations
/*
    what does bitwise and do?
    
    if there is already a set bit, it can either take it away if it is 0 or keep it
    otherwise it will make no change

    this means that and can only lower k or keep it the same

    therefore, we should try to avoid having zeros that are in the and that take away set bits

    bitwise or just guarantees that we have a set bit if there is a bit

    we can only add a bit with or

    from 1 to n, all the bits are covered from 0th bit up to the bit of the largest power of 2 in the range

    we should do bits with precedence, because having one bit higher is better than having all the lower bits set

    start with the highest bit, and put all values that have that highest bit in the even positions if possible

    then keep going down the list of numbers sorted descendingly and do that until we run out of positions

    then just fill the remaining positions however we want

    is this actually optimal?

    becuase it is ordered, we can actually do an & before an or and avoid removing the bit

    this essentially means that we can try to have the largest element be the last or and the smallest element be the last and

    so we should sort ascendingly with the larger numbers in the ors, and then sort descendingly for the ands

    this doesn't seem to be completely accurate - lets move on to individual bits instead

    we want to ensure that the largest bits fit

    as we loop through the original numbers 1 through n, we should sort them by their highest bit

    now we need to ensure that the highest bit is able to exist

    we should or the highest bit as close to the end as possible, and with the other instances of the highest bit 



*/
 

// Claims on algo 
/*  
    new approach, what does the bits from 1 to n look like? it is not just random numbers, so there may be a specific rule we can use

    000000000001
    000000000010
    000000000011
    000000000100
    000000000101
    000000000110
    000000000111
    ...
    every bit will be covered up to the largest power of 2 <= n

    therefore the upper bound is that

    is it always possible to achieve by proper ordering?
    
    if the largest power of 2 less than n is there, there also exists the largest power of 2 - 1, which has all the set bits

    we can or this at the end and immediately get everything we need

    if the number is not a power of 2, we can make this structure

    .........                2**k + 1 something  2 ** k - 1, 2**k
                                or        and        or       and
    this guarantees all bits will be set 

    otherwise, we can still or the 2**k and the 2**k - 1 and then we should and 1 at the very end if necessary, making all bits set except for the smallest

    all the above is a logical mistake, because anding with zero bits will set the others to zero, ruining the value of k

    we have to and to save bits from being removed, meaning that after they are added we need to ensure that they do not get removed

    if not a power of two, we can always ensure the largest bit by putting the power of 2 as or close to the end

    then we can keep it by using the power of 2 + 1 as an and at the end

    lets restart our logic

    if we can have an or at the end, meaning that n is even, we should or with all the bits we can by using the greatest power of 2 minus 1

    if n is not a power of 2, put the highest power of 2 as or, then highest power + 1 as and, and then do the highest power - 1 as or on the last one

    this guarantees every bit to be set

    if n is a power of 2, we can only guarantee the highest bit if we or it at the end because it cannot survive if anded by any other value

    therefore, everything in front does not matter, just or the highest power of 2 at the very end

    what happens when n is odd?

    this means that the last operation is an and, so the answer is bounded by the final number

    we should use n as the last element because it is the largest

    then we need to set the bits of n by using or

    we can or by n - 1 on the previous element to get the highest number possible

    if n - 1 is even, we can also or by 1 to get n which is the higest possible

    this is the only case that matters because you cannot get higher than n, and you already guarantee n - 1, so changing any other bit would get you higher than n which just gets reset back


    psuedocode:

    if n is even:
        if n is not a power of 2:
            structure -- > blah blah blah 2**k 2**k + 1, 2**k - 1
        else:
            just put the power of 2 as the last element
    else:
        structure --> blah blah blah n-1 n
*/

void test_case(){
    int n; cin >> n;
    vector<int> ans(n);
    int p2;
    for(int b = 30; b >= 1; b--){
        if(n & (1 << b)){
            p2 = (1 << b);
            break;
        }
    }
    if(n % 2 == 0 && n != p2){
        ans[n-3] = p2;
        ans[n-2] = p2 + 1;
        ans[n-1] = p2 - 1;
        int x = 1;
        for(int i = 0; i < n - 3; i++){
            while(abs(x - p2) <= 1){
                x++;
            }
            ans[i] = x;
            x++;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            ans[i] = i + 1;
        }
    }
    swap(ans[0], ans[1]);
    int k = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) k &= ans[i];
        else k |= ans[i];
    }
    cout << k << '\n';
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "\n" : " ");
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