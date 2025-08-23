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
    given a bracket sequence

    need to color the sequence using the minimal number of colors possible

    If you take all the elements of the color in the order they appear and concatenate them, it creates either a regular bracket sequence or the reverse of a regular bracket sequence
*/
 

// Small Observations
/*
    When is it not possible to have a beautiful bracket sequence?
    
    )(()())( -- > ())()(()

    this one doesn't work because it is wrong in regular order but also has problems in the reversed order

    What does "the order of the characters is reversed" really mean?

    it means the last character swaps with the first, second to last with the second, etc.

    Algorithmically, we could just try to look at the elements from the end as well to see if we can paint more 

    Let's reduce the problem to just being regular bracket sequences

    We can always paint an opening bracket if there is a closing bracket in the future that it can match with

    We should always paint a closing bracket if our current count of opening brackets without a pair is greater than 0

    We can keep a suffix count of the number of closing brackets, and always add an opening bracket if suffix is greater than the number of unclosed

    There must be at least 2 brackets in each color, because sequences of length 1 are never good

    More generally, a good sequence must be of even length, otherwise there will be one bracket that is guaranteed to not have a pair (reversed or not)

    This means that we can never paint a sequence of odd length, because even subsequences cannot cover the entire odd segment

    What happens if we do not have the same number of opening and closing brackets?

    This means that some elements will not be able to have a pair

    This also covers the case of n being odd because that means one of the number of brackets must be different from the other (one is odd, one is even)

    However, this adds the extra cases of even length but not being able to pair everything
    
    Now we have a somewhat simplified problem where we know that every opening bracket has a pair

    We have an equal number of opening and closing brackets

    There cannot be too many closing brackets or opening brackets or that will cause the sequence to not be beautiful, regardless of reversing or not

    Can we just paint contiguous intervals?

    ((()))))((

    Let's just consider the first element

    we know that eventually we have to paint it

    are we able to determine straight away what sequence it should be a part of?

    does it have to pair with a closing bracket?

    yes, there has to be a closing bracket in the sequence that pairs with it

    if there wasn't a closing bracket, it would be bad no matter what the order is

    let's make a counter and say that we have one element that we need to pair

    If the next element is the opposite, we can pair it straight away, and we no longer need to pair it

    (((())

    I'm really struggling with the idea of reversing

    What is a regular bracket sequence in the first place?

    We can define it by the way we determine it

    As we go from left to right, there are never more closing brackets than opening brackets

    When we open a bracket, we add to the count

    When we close a bracket, we decrease the count

    If the count is ever negative, it is not a valid bracket sequence

    If the count at the very end is positive, it is not a valid bracket sequence

    Now, all we did was reverse the string!
    
    This means that we traverse everything the opposite direction, so every closing bracket from the end should be treated as an opening bracket, and every opening bracket should be treated as a closing bracket

*/
 

// Claims on algo 
/*  
    When reversing we can do the same algorithm as RBS but starting from the end and treating the counts in the opposite way

    This means that a beautiful string can have prefixes with balance that is either negative or positive, but it must be the same for all prefixes

    Additionally, a beautiful string must always have a balance of zero over the length of the string, meaning the same number of opening and closing brackets

    If we go from the end of the string, we know that we cannot have a positive balance because then it would open the wrong way

    This is the mirrored case of going from the front, and it accounts for reversals

    If we currently have a positive or negative prefix, we need to maintain that sign for the rest of the subsequence

    Therefore, if there is ever an element that would change the sign, we cannot add it

    )))(((())(()

    we cannot add the next element after the first size, because the sign of the balance would change from negative to positive

    This means that instead we should skip that element and try to pick more elements that make it negative

    What about knowing when to stop picking elements? Sometimes picking it will be bad because we need to get to 0 balance at the end

    We can only color a string if the balance is zero

    If we look at every prefix with a balance of zero, we can keep track of the indices where the balance becomes zero

    This would mean that in between any two indices there is a string with a balance of zero

    If we look at only the adjacent indices we know that its balance is either always positive or always negative, because if there was any change in balance we would get a zero in between them, but we didn't

    Now we know that we can color all these segments with balance of positive to one color, because the balance will always be positive and it will end as zero

    We can also do the same with all the segments that are negative

    If there are only segments that are postitive, we can color it in one operation, same with only negative

    Otherwise we need two operations

    
*/

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    int opening = 0, closing = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') opening++;
        else closing++;
    }
    if(opening != closing){
        cout << "-1\n";
        return;
    }
    // if the segment is positive, color it 1, otherwise color it 2
    vector<int> ans(n);
    int balance = 0;
    for(int i = 0; i < n; i++){
        int prev_balance = balance;
        if(s[i] == '(') balance++;
        else balance--;
        if(balance == 0){
            if(prev_balance > 0){
                ans[i] = 1;
            }
            else ans[i] = 2;
        }
        else{
            if(balance > 0) ans[i] = 1;
            else ans[i] = 2;
        }
    }
    bool both = find(ans.begin(), ans.end(), 1) != ans.end() && find(ans.begin(), ans.end(), 2) != ans.end();
    cout << (both ? 2 : 1) << '\n';
    if(!both){
        for(int i = 0; i < n; i++) ans[i] = 1;
    }
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