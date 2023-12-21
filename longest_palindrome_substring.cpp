#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n=s.size();
    unordered_map<char,int> freq;
    int i=0;
    int j=0;
    int maxlen=INT_MIN;
    string temp;
    string output="";

    while(j<n){
        freq[s[j]]++;
        if(freq[s[j]]>1){
            i=j-1;
            while(s[i]!=s[j]){
                i--;
            }
            temp=s.substr(i,j-i+1);
            int m=temp.size();
            //cout<<temp<<"  "<<temp.size()<<endl;
            if(m>maxlen){
                output=temp;
                //cout<<output<<"---->  "<<"IF"<<endl;
                maxlen=temp.size();
            }
        }

        j++;
    }

    return output;
}

int main(){
    string s;
    cin>>s;
    string ans=longestPalindrome(s);
    cout<<ans;
}
