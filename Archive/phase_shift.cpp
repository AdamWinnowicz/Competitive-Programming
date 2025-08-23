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
    we have a string t

    what is the lex smallest string that could have become t if

    there was some order of letters such that each letter is replaced by another distinct letter
*/
 

// Small Observations
/*
    when we start constructing a circle, components start to appear

    these componenets start with just one edge from a --> b

    then, we can add onto these components by either having something else point into a, or having b point into something else

    because lex smallest proceess is greedy, we can try to find the best fit for each letter as we go from left to right and it will bring us to the optimal solution

    if we are at a current letter, we want its parent to be as small as possible

    we should be able to loop over the set of parents (letters) and stop as soon as we find one that works

    if we already designated a parent for a letter, we have to use that

    otherwise, we need to loop and check some conditions

    look at the shape of the graph

    e.g. a -- > b -- > c

    if a value already has a child, we cannot use it as a parent

    we should mark every letter as having a child as soon as we make it the parent of something

    however, there is a special case

    if we are considering the letter at the front of a chain, if the chain is already 26 long we can only use the value at the end of the chain to close the loop, so the only one that stil doesn't have a child

    we cannot close the loop earlier than that though

    meaning that the end of the current chain is off limits as a parent of the start of the chain

    
*/
 

// Claims on algo 
/*  
    because there are so few letters, we can probably simulate some recursive (dfs-like) function that finds the end of the current segment and checks the length
*/

char last_in_segment(char start, map<char,char> & child){
    char curr = start;
    int len = 1;
    while(child.find(curr) != child.end()){
        curr = child[curr];
        len++;
    }
    if(len == 26) curr = '!';
    return curr;
}

void test_case(){
    int n; cin >> n;
    string t; cin >> t;
    map<char, char> child;
    bool haschild[27] = {false};
    for(int i = 0; i < n; i++){
        bool found = false;
        for(const auto & p : child){
            if(p.second == t[i]){
                t[i] = p.first;
                found = true;
                break;
            }
        }
        if(found) continue;
        char not_possible = last_in_segment(t[i], child);
        for(char c = 'a'; c <= 'z'; c++){
            if(haschild[c - 'a'] == false && c != t[i] && c != not_possible){
                child[c] = t[i];
                haschild[c - 'a'] = true;
                t[i] = c;
                break;
            }
        }
    }
    cout << t << '\n';
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