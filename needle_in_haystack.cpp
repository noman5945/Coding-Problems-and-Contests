#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int n=needle.size();
    int en=haystack.size();
    int i=0;


    while(i<en){
        string subs=haystack.substr(i,n);
        if(subs==needle){
            return i;
        }
        i++;
    }

    return -1;
}

int main(){
    string needle="leeto";
    string hayStack="leetcode";
    cout<<strStr(hayStack,needle)<<endl;
}
