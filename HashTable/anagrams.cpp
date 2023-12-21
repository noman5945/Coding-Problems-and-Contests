#include<bits/stdc++.h>
using namespace std;

int count_anagram_pairs(string &sen){
    int i=0;
    int j=0;
    unordered_map<string,int> temp_freq;
    int cnt=0;

    while(j<sen.size()){
        string st=sen.substr(i,j);
            
        j++;
    }
}

int main(){
    string s;
    cin>>s;

    cout<<count_anagram_pairs(s)<<endl;
}