#include<bits/stdc++.h>
using namespace std;

//approach 1 : Subtract same chars from map. Extra char will be left with 1 which is the ans

char findTheDifference(string s, string t) {
    
    char ans;
    map<char,int> freq;
    for(char che:t){
        freq[che]++;
    }
    for(char chs:s){
        freq[chs]--;
    }
    for(auto i=freq.begin();i!=freq.end();i++){
        if(i->second==1){
            ans=i->first;
        }
    }
    return ans;
}

//approach 2: Bitwise XOR operation
/**
 *  XOR (^) has useful properties:
    x ^ x = 0 (same numbers cancel out).
    x ^ 0 = x (XOR with 0 keeps the number unchanged).
    Order doesn’t matter in XOR.
    If we XOR all characters in s and t, the matching characters cancel out, and we are left with the extra character in t.
 */
char findTheDifference_bitwise_XOR(string s, string t) {
    string bigString=s+t;
    
    char chXOR=0;
    for(char che:bigString){
        chXOR=chXOR^che;
    }
    return chXOR;
    
}


int main(){
    string s="abcd", t="abcde";
    char ans=findTheDifference(s,t);
    char bit_ans=findTheDifference_bitwise_XOR(s,t);
    cout<<ans<<" Bitwise XOR ans-->"<<bit_ans<<endl;
}