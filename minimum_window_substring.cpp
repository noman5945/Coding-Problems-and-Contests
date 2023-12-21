#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
        /*int m=s.size();
        int n=t.size();
        int minlen=INT_MAX;
        string output="";
        unordered_map<char,int> freq;

        for(int i=0;i<n;i++){
            freq[t[i]]++;
        }

        int i=0;
        int j=0;
        int check=n;
        int minStart;

        while(j<m){
            if(freq[s[j]]>0){
                check--;

            }
            freq[s[j]]--;
            j++;
            if(check==0){
                if(minlen>abs(j-i)){
                    minStart=i;
                    minlen=j-i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0){
                    check++;
                }
                i++;
            }
        }
        if(minlen!=INT_MAX){
            output=s.substr(minStart,minlen);
            return output;
        }

        return output;
        */

 // count of char in t
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }

        int i = 0;
        int j = 0;

        // # of chars in t that must be in s
        int counter = t.size();

        int minStart = 0;
        int minLength = INT_MAX;

        while (j < s.size()) {
            // if char in s exists in t, decrease
            if (m[s[j]] > 0) {
                counter--;
            }
            // if char doesn't exist in t, will be -'ve
            m[s[j]]--;
            // move j to find valid window
            j++;

            // when window found, move i to find smaller
            while (counter == 0) {
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }

                m[s[i]]++;
                // when char exists in t, increase
                if (m[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }

        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
}


int main(){
    string s,t;
    cin>>s>>t;
    string ans=minWindow(s,t);
    cout<<ans<<endl;
}
