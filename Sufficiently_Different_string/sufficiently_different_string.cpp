#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> alpha={{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8},{'i',9},{'j',10},{'k',11},
{'l',12},{'m',13},{'n',14},{'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},{'u',21},{'v',22},
{'w',23},{'x',24},{'y',25},{'z',26}};

/**
 * A little problamatic
 */
string sufficently_different_string(string s,int dup){
    if(s.length()==26){
        return "NOPE";
    }
    string ans="";
    string final_ans="";
    int n=s.length();
    unordered_map<char,int> found;
    for(char c:s){
        found[c]=alpha[c];
    }
    for(auto i=alpha.begin();i!=alpha.end();i++){
        if(!found[i->first]){
            ans+=i->first;
        }
    }
    int m=ans.length();
    while(n>=0){
        final_ans+=ans[m];
        m--;
        n--;
    }

    return final_ans;
}

/**
 * Correct with much optimized
 */
string sufficiently_different_string_chatGPT(string s, int dup) {
    int n = s.length();
    if (n == 26) return "NOPE";  // If string s has all 26 unique characters, return "NOPE"
    
    unordered_set<char> found(s.begin(), s.end());  // Set of characters already in string s
    string available_chars = "";

    // Collect characters that are not in string s
    for (char c = 'a'; c <= 'z'; c++) {
        if (found.find(c) == found.end()) {
            available_chars += c;
        }
    }

    string ans = "";
    int overlap_count = 0;

    // Now, we want to fill ans with available characters
    for (char c : available_chars) {
        if (ans.length() < n) {
            ans += c;  // Keep adding characters from available set
        } else {
            break;
        }
    }

    // If the length of ans is not equal to n, it's impossible to generate such a string
    if (ans.length() < n) {
        return "NOPE";
    }

    // Construct the lexicographically smallest string t with <= k overlaps
    int overlap = 0;
    for (int i = 0; i < n; i++) {
        if (found.find(ans[i]) != found.end()) {
            overlap++;  // Increase overlap count if the character is also in s
        }
    }

    if (overlap > dup) {
        return "NOPE";  // If overlap is greater than k, return "NOPE"
    }

    return ans;  // Return the valid result string
}

/**
 * Much better solution
 */
void solve(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();

    vector<int> freq(26, 0);
    for (char c : s) 
        freq[c - 'a']++;

    string ans = "";
    int common = 0;
        
    for (int i = 0; i < 26 && ans.length() < n; i++) {
        if (freq[i] > 0) {
            if (common < k) {
                ans += ('a' + i);
                common++;
            }
        }
        else {
            ans += ('a' + i);
        }
    }

    if (ans.length() < n) 
        cout << "NOPE" << endl;
    else 
        cout << ans << endl;
}

int main(){
    int dup;
    string s;
    cin>>s>>dup;
    string ans=sufficently_different_string(s,dup);
    cout<<ans<<endl;

}